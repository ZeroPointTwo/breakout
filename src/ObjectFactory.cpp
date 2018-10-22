#include "ObjectFactory.h"
#include "SFML/Graphics.hpp"

Breakout::ObjectFactory::ObjectFactory() {}

Breakout::ObjectFactory::~ObjectFactory() {}

std::shared_ptr<Breakout::Object> Breakout::ObjectFactory::TestCreateBrick(float x, float y, sf::Color color)
{
    // Create the object
    auto object = std::make_shared<Breakout::Object>();

    // Render component
    auto brickShape = std::make_shared<sf::RectangleShape>(sf::Vector2f(50.f, 20.f));
    brickShape->setFillColor(color);
    std::shared_ptr<Breakout::RenderComponent> render = std::make_shared<Breakout::RenderComponent>(brickShape);
    object->AddComponent(render);

    // Position component
    std::shared_ptr<Breakout::PositionComponent> position = std::make_shared<Breakout::PositionComponent>();
    position->SetPosition(sf::Vector2f(x, y));
    object->AddComponent(position);

    // return it
    return object;
}
