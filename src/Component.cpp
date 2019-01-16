#include "Component.h"
#include "Object.h"
#include "SFML\Graphics\Rect.hpp"
#include "SFML\Graphics\Shape.hpp"
#include "SFML\Window\Keyboard.hpp"
#include "Util.h"

using namespace Breakout;

Breakout::BaseComponent::BaseComponent(const std::weak_ptr<Object>& _owner) : type(CT_INVALID)
{
    owner = _owner;
}

Breakout::EComponentType Breakout::BaseComponent::GetType()
{
    return type;
}

std::weak_ptr<Object> Breakout::BaseComponent::GetOwner()
{
    return owner;
}

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-------------------------------------

Breakout::RenderComponent::RenderComponent(const std::weak_ptr<Object>&      _owner,
                                           const std::shared_ptr<sf::Shape>& inRenderObject) :
    BaseComponent(_owner),
    RenderObject(inRenderObject)
{
    type = CT_RENDERCOMPONENT;
}

Breakout::RenderComponent::~RenderComponent()
{
}

bool Breakout::RenderComponent::Init()
{
    return true;
}

void Breakout::RenderComponent::Update(float dt)
{
    UNUSED_ARGS(dt);
}

void Breakout::RenderComponent::UnInit()
{
}

sf::Shape* Breakout::RenderComponent::GetShape()
{
    return RenderObject.get();
}

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-------------------------------------

Breakout::PositionComponent::PositionComponent(const std::weak_ptr<Object>& _owner) : BaseComponent(_owner)
{
    type = CT_POSITIONCOMPONENT;
}

Breakout::PositionComponent::~PositionComponent()
{
}

bool Breakout::PositionComponent::Init()
{
    return true;
}

void Breakout::PositionComponent::Update(float dt)
{
    UNUSED_ARGS(dt);
}

void Breakout::PositionComponent::UnInit()
{
}

void Breakout::PositionComponent::SetPosition(const sf::Vector2f& newPosition)
{
    Position = newPosition;
}

const sf::Vector2f& Breakout::PositionComponent::GetPosition() const
{
    return Position;
}

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-------------------------------------

Breakout::InputComponent::InputComponent(const std::weak_ptr<Object>& _owner) : BaseComponent(_owner)
{
    type = CT_INPUTCOMPONENT;
}

bool Breakout::InputComponent::Init()
{
    return false;
}

void Breakout::InputComponent::Update(float dt)
{
    UNUSED_ARGS(dt);
}

void Breakout::InputComponent::UnInit()
{
}

void Breakout::InputComponent::SetInputs(GameInputs inputs)
{
    currentInputs = inputs;
}

GameInputs Breakout::InputComponent::GetInputs()
{
    return currentInputs;
}

Breakout::MovementComponent::MovementComponent(const std::weak_ptr<Object>& _owner) : 
    BaseComponent(_owner),
    velocity(0.f, 0.f),
    acceleration(0.f, 0.f)
{
}

bool Breakout::MovementComponent::Init()
{
    return false;
}

void Breakout::MovementComponent::Update(float dt)
{
    UNUSED_ARGS(dt);
}

void Breakout::MovementComponent::UnInit()
{
}

Breakout::PaddleMovementComponent::PaddleMovementComponent(const std::weak_ptr<Object>& _owner,
                                                           float                        _speed,
                                                           float                        _boundLeft,
                                                           float                        _boundRight) :
    MovementComponent(_owner),
    speed(_speed),
    boundLeft(_boundLeft),
    boundRight(_boundRight)
{
    type = CT_PADDLEMOVEMENTCOMPONENT;
}

bool Breakout::PaddleMovementComponent::Init()
{
    return false;
}

void Breakout::PaddleMovementComponent::Update(float dt)
{
    UNUSED_ARGS(dt);
    auto inputComp = owner.lock()->GetComponent<InputComponent>();
    Assert(inputComp != nullptr, "PaddleMovementComponent Components must have a Input Component");

    if (inputComp)
    {
        GameInputs   curInputs = inputComp->GetInputs();

        float modifier = curInputs.moveLeft ? -1.0f : 1.0f;

        if (curInputs.moveLeft == curInputs.moveRight)
        {
            modifier = 0;
        }

        velocity.x = modifier * speed;
    }
}
void Breakout::PaddleMovementComponent::UnInit()
{
}

Breakout::CollisionComponent::CollisionComponent(const std::weak_ptr<Object>&     _owner,
                                                 const std::shared_ptr<sf::Shape> inCollisionShape) :
    BaseComponent(_owner)
{
    collisionRect = inCollisionShape->getGlobalBounds();
    type          = CT_COLLISIONCOMPONENT;
}

CollisionComponent::~CollisionComponent()
{
}

bool CollisionComponent::Init()
{
    return false;
}

void CollisionComponent::Update(float dt)
{
    UNUSED_ARGS(dt);
}

void CollisionComponent::UnInit()
{
}

sf::Rect<float> CollisionComponent::GetTransformed()
{
    sf::Rect<float> outRect;

    if (auto _owner = GetOwner().lock())
    {
        if (auto posComponent = _owner->GetComponent<PositionComponent>())
        {
            auto ourPosition = posComponent->GetPosition();
            outRect.top      = collisionRect.top + ourPosition.y;
            outRect.left     = collisionRect.left + ourPosition.x;
            outRect.height   = collisionRect.height;
            outRect.width    = collisionRect.width;
        }
    }
    return outRect;
}

bool CollisionComponent::Intersects(CollisionComponent* other) const
{
    if (other->collisionRect.intersects(collisionRect))
    {
        return true;
    }

    return false;
}
