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

Breakout::InputComponent::InputComponent(const std::weak_ptr<Object>& _owner) : BaseComponent(_owner) {}

bool Breakout::InputComponent::Init() { return false; }

void Breakout::InputComponent::Update(float dt)
{
    UNUSED_ARGS(dt);

    // Todo: actually do something with the input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        // owner.move_yourself
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        // owner.move_otherway
    }
}

void Breakout::InputComponent::UnInit() {}
