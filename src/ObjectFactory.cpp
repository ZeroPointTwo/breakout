#include "ObjectFactory.h"
#include "SFML/Graphics.hpp"

Breakout::ObjectFactory::ObjectFactory() {}

Breakout::ObjectFactory::~ObjectFactory() {}

std::shared_ptr<Breakout::Object> Breakout::ObjectFactory::TestCreateBrick(
    float x, float y, float width, float height, sf::Color color)
{
    Assert(width > 0, "Width must be > 0 (width: {})", width);
    Assert(height > 0, "Height must be > 0 (height: {})", height);

    // Create the object
    auto object = std::make_shared<Breakout::Object>();

    // Render component
    auto brickShape = std::make_shared<sf::RectangleShape>(sf::Vector2f(width, height));
    brickShape->setFillColor(color);
    std::shared_ptr<Breakout::RenderComponent> render = std::make_shared<Breakout::RenderComponent>(object, brickShape);
    object->AddComponent(render);

    // Position component
    std::shared_ptr<Breakout::PositionComponent> position = std::make_shared<Breakout::PositionComponent>(object);
    position->SetPosition(sf::Vector2f(x, y));
    object->AddComponent(position);

    // return it
    return object;
}

std::shared_ptr<Object> Breakout::ObjectFactory::CreatePaddle(
    float x, float y, float width, float height, sf::Color color)
{
    UNUSED_ARGS(color, x, y, width, height);

    // Create the object
    auto object = std::make_shared<Breakout::Object>();

    // Render component
    auto paddleShape = std::make_shared<sf::RectangleShape>(sf::Vector2f(width, height));
    paddleShape->setFillColor(color);

    std::shared_ptr<Breakout::RenderComponent> render =
        std::make_shared<Breakout::RenderComponent>(object, paddleShape);
    object->AddComponent(render);

    // Position component
    std::shared_ptr<Breakout::PositionComponent> position = std::make_shared<Breakout::PositionComponent>(object);
    position->SetPosition(sf::Vector2f(x, y));
    object->AddComponent(position);

    // Input component
    std::shared_ptr<Breakout::InputComponent> input = std::make_shared<Breakout::InputComponent>(object);
    object->AddComponent(input);

    return object;
}
