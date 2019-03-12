#include "Component.h"
#include "Object.h"
#include "CollisionReaction.h"
#include "SFML\Graphics\Rect.hpp"
#include "SFML\Graphics\Shape.hpp"
#include "SFML\Window\Keyboard.hpp"
#include "Util.h"

using namespace Breakout;

Breakout::BaseComponent::BaseComponent(const std::weak_ptr<Object>& _owner)
{
    owner = _owner;
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

Breakout::MovementComponent::MovementComponent(const std::weak_ptr<Object>& _owner, const sf::Vector2f& vel) :
    BaseComponent(_owner),
    velocity(vel),
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
    MovementComponent(_owner, sf::Vector2f(0, 0)),
    speed(_speed),
    boundLeft(_boundLeft),
    boundRight(_boundRight)
{
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
        GameInputs curInputs = inputComp->GetInputs();

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
                                                 const std::shared_ptr<sf::Shape> inCollisionShape,
                                                    const std::string& inCollisionReaction) :
    BaseComponent(_owner),
    collisionReaction(inCollisionReaction)
{
    sf::Rect<float> collisionRect = inCollisionShape->getGlobalBounds();
    aabb.pos.x = collisionRect.left + collisionRect.width / 2.f;
    aabb.pos.y = collisionRect.top + collisionRect.height / 2.f;
    aabb.half.x = collisionRect.width / 2.f;
    aabb.half.y = collisionRect.height / 2.f;
}

CollisionComponent::~CollisionComponent()
{
}

bool CollisionComponent::Init()
{
        
    return true;
}

void CollisionComponent::Update(float dt)
{
    UNUSED_ARGS(dt);
}

void CollisionComponent::UnInit()
{
}

CollisionComponent::AABB CollisionComponent::GetTransformed()
{
    AABB ret = this->aabb;

    if (auto _owner = GetOwner().lock())
    {
        if (auto posComponent = _owner->GetComponent<PositionComponent>())
        {
            auto ourPosition = posComponent->GetPosition();
            ret.pos += ourPosition;
        }
    }

    return ret;
}

//bool CollisionComponent::Intersects(CollisionComponent* other)
//{
//    if (other != nullptr)
//    {
//        return other->GetTransformed().intersects(GetTransformed());
//    }

 //   return false;
//}

void CollisionComponent::InjectReaction(const std::string& reactionId, Collision::CollisionChannel channel)
{
    UNUSED_ARGS(reactionId, channel);


}

CollisionComponent::AABB CollisionComponent::GetAABB(void)
{
    return aabb;
}

CollisionComponent::Hit CollisionComponent::IntersectAABB(CollisionComponent* other)
{
    // TODO: FIX ME
    Hit hit;

    AABB otherAABB = other->GetAABB();

    float dx = otherAABB.pos.x - this->aabb.pos.x;
    float px = (otherAABB.half.x + this->aabb.half.x) - abs(dx);
    if (px <= 0) {
        hit.isHit = false;
    }

    float dy = otherAABB.pos.y - this->aabb.pos.y;
    float py = (otherAABB.half.y + this->aabb.half.y) - abs(dy);
    if (py <= 0) {
        hit.isHit = false;
    }
    
    if (px < py) {
        float sx = dx < 0.f ? -1.f : 1.f;
        hit.delta.x = px * sx;
        hit.normal.x = sx;
        hit.pos.x = this->aabb.pos.x + (this->aabb.half.x * sx);
        hit.pos.y = otherAABB.pos.y;
        hit.isHit = true;
    }
    else {
        float sy = dy < 0.f ? -1.f : 1.f;
        hit.delta.y = py * sy;
        hit.normal.y = sy;
        hit.pos.x = otherAABB.pos.x;
        hit.pos.y = this->aabb.pos.y + (this->aabb.half.y * sy);
        hit.isHit = true;
    }

    return hit;
}

