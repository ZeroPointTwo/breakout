#include "Component.h"
#include "Object.h"
#include "SFML\Window\Keyboard.hpp"
#include "Util.h"

using namespace Breakout;

Breakout::BaseComponent::BaseComponent(const std::weak_ptr<Object>& _owner) : type(CT_INVALID) { owner = _owner; }

Breakout::EComponentType Breakout::BaseComponent::GetType() { return type; }

std::weak_ptr<Object> Breakout::BaseComponent::GetOwner() { return owner; }

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

Breakout::RenderComponent::~RenderComponent() {}

bool Breakout::RenderComponent::Init() { return true; }

void Breakout::RenderComponent::Update(float dt) { UNUSED_ARGS(dt); }

void Breakout::RenderComponent::UnInit() {}

sf::Shape* Breakout::RenderComponent::GetShape() { return RenderObject.get(); }

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-------------------------------------

Breakout::PositionComponent::PositionComponent(const std::weak_ptr<Object>& _owner) : BaseComponent(_owner)
{
    type = CT_POSITIONCOMPONENT;
}

Breakout::PositionComponent::~PositionComponent() {}

bool Breakout::PositionComponent::Init() { return true; }

void Breakout::PositionComponent::Update(float dt) { UNUSED_ARGS(dt); }

void Breakout::PositionComponent::UnInit() {}

void Breakout::PositionComponent::SetPosition(const sf::Vector2f& newPosition) { Position = newPosition; }

const sf::Vector2f& Breakout::PositionComponent::GetPosition() const { return Position; }

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-------------------------------------

Breakout::InputComponent::InputComponent(const std::weak_ptr<Object>& _owner) : BaseComponent(_owner)
{
    type = CT_INPUTCOMPONENT;
}

bool Breakout::InputComponent::Init() { return false; }

void Breakout::InputComponent::Update(float dt) { UNUSED_ARGS(dt); }

void Breakout::InputComponent::UnInit() {}

void Breakout::InputComponent::SetInputs(GameInputs inputs) { currentInputs = inputs; }

GameInputs Breakout::InputComponent::GetInputs() { return currentInputs; }

Breakout::MovementComponent::MovementComponent(const std::weak_ptr<Object>& _owner) : BaseComponent(_owner) {}

bool Breakout::MovementComponent::Init() { return false; }

void Breakout::MovementComponent::Update(float dt) { UNUSED_ARGS(dt); }

void Breakout::MovementComponent::UnInit() {}

Breakout::PaddleMovementComponent::PaddleMovementComponent(const std::weak_ptr<Object>& _owner) :
    MovementComponent(_owner)
{
}

bool Breakout::PaddleMovementComponent::Init() { return false; }

void Breakout::PaddleMovementComponent::Update(float dt)
{
    auto positionComp =
        dynamic_cast<PositionComponent*>(owner.lock()->GetComponent(EComponentType::CT_POSITIONCOMPONENT));
    Assert(positionComp != nullptr, "PaddleMovementComponent Components must have a Position Component");
    auto inputComp = dynamic_cast<InputComponent*>(owner.lock()->GetComponent(EComponentType::CT_INPUTCOMPONENT));
    Assert(positionComp != nullptr, "PaddleMovementComponent Components must have a Input Component");

    if (positionComp && inputComp)
    {
        GameInputs   curInputs = inputComp->GetInputs();
        sf::Vector2f oldPos    = positionComp->GetPosition();

        // TODO speed
        float speed = 1.0f;

        float modifier = curInputs.moveLeft ? -1.0f : 1.0f;

        if (curInputs.moveLeft == curInputs.moveRight) { modifier = 0; }

        float deltaPos = speed * dt * modifier;

        oldPos.x += deltaPos;
    }
}
void Breakout::PaddleMovementComponent::UnInit() {}
