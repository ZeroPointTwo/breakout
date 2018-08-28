#include "Component.h"

using Breakout::BaseComponent;

Breakout::RenderComponent::RenderComponent(const std::shared_ptr<sf::Shape>& inRenderObject) :
    RenderObject(inRenderObject)
{
}

Breakout::RenderComponent::~RenderComponent() {}

bool Breakout::RenderComponent::Init() { return true; }

void Breakout::RenderComponent::Update(float dt)
{
    // todo:  DRAW ME and cry
    //                    -Joel
}

void Breakout::RenderComponent::UnInit() {}

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-------------------------------------

Breakout::PositionComponent::PositionComponent() {}

Breakout::PositionComponent::~PositionComponent() {}

bool Breakout::PositionComponent::Init() { return true; }

void Breakout::PositionComponent::Update(float dt) {}

void Breakout::PositionComponent::UnInit() {}

void Breakout::PositionComponent::SetPosition(const sf::Vector2f& newPosition) { Position = newPosition; }

const sf::Vector2f& Breakout::PositionComponent::GetPosition() const { return Position; }
