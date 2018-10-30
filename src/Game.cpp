#include "Game.h"
#include "Component.h"
#include "SFML/Graphics.hpp"
#include "nlohmann/json.hpp"

bool Breakout::BreakoutGame::Init(std::shared_ptr<sf::RenderWindow>& sfWindow)
{
    bool isSuccess = false;

    _sfWindow = sfWindow;

    objectFactory = std::make_unique<ObjectFactory>();

    // make an object that would otherwise be made by a mythical objectfactory
    // Object testObject{};

    // Make a circle just because
    // auto testCircle = std::make_shared<sf::CircleShape>(1.f);
    // testCircle->setScale(
    //    sf::Vector2f(static_cast<float>(50) * 0.5f,
    //        static_cast<float>(50) * 0.5f));  // Scale the circle to make an ellipses
    // testCircle->setFillColor(sf::Color::Green);
    //
    // auto renderComponent = std::make_shared<RenderComponent>(testCircle);
    // testObject.AddComponent(renderComponent);
    //_gameObjects.push_back(testObject);

    return isSuccess;
}

void Breakout::BreakoutGame::BeginGame()
{
    EndGame();
    Init(_sfWindow);

    auto level = R"(
    {
        "level_data" : "--RRR---RRR--",
        "brick_height" : 10,
        "brick_width" : 15,
        "brick_gap" : 1
    }
    )"_json;

    std::string  level_data   = level["level_data"];
    std::int32_t brick_width  = level["brick_width"];
    std::int32_t brick_height = level["brick_height"];
    std::int32_t brick_gap    = level["brick_gap"];

    sf::Vector2f position(0.0f, 0.0f);
    for (auto element : level_data)
    {
        switch (element)
        {
            case 'R':
                _gameObjects.push_back(objectFactory->TestCreateBrick(
                    position.x, position.y, (float)brick_width, (float)brick_height, sf::Color::Red));
                break;
            case '-': break;
            default: break;
        }
        position.x += brick_width + brick_gap;
    }
    position.y += brick_height + brick_gap;
    // for (int i = 0; i < 10; ++i)
    //{
    //    for (int j = 0; j < 10; ++j)
    //    {
    //        // formatting
    //        _gameObjects.push_back(objectFactory->TestCreateBrick(i * 51.f, j * 21.f, sf::Color::Red));
    //    }
    //}
}
