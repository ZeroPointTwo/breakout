#include "Component.h"
#include "Util.h"

// using Breakout::BaseComponent;

Breakout::BaseComponent::BaseComponent() : type(CT_INVALID) {}

Breakout::EComponentType Breakout::BaseComponent::GetType() { return type; }

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-------------------------------------

Breakout::RenderComponent::RenderComponent(const std::shared_ptr<sf::Shape>& inRenderObject) :
    RenderObject(inRenderObject)
{
    type = CT_RENDERCOMPONENT;
}

Breakout::RenderComponent::~RenderComponent() {}

bool Breakout::RenderComponent::Init() { return true; }

void Breakout::RenderComponent::Update(float dt)
{
    UNUSED_ARGS(dt);
    // todo:  DRAW ME and cry
    //                    -Joel
}

void Breakout::RenderComponent::UnInit() {}

sf::Shape* Breakout::RenderComponent::GetShape()
{
    return RenderObject.get();
}

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-------------------------------------

Breakout::PositionComponent::PositionComponent() { type = CT_POSITIONCOMPONENT; }

Breakout::PositionComponent::~PositionComponent() {}

bool Breakout::PositionComponent::Init() { return true; }

void Breakout::PositionComponent::Update(float dt) { UNUSED_ARGS(dt); }

void Breakout::PositionComponent::UnInit() {}

void Breakout::PositionComponent::SetPosition(const sf::Vector2f& newPosition) { Position = newPosition; }

const sf::Vector2f& Breakout::PositionComponent::GetPosition() const { return Position; }

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-------------------------------------
