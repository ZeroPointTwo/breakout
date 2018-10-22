#include "Game.h"
#include "Component.h"
#include "SFML/Graphics.hpp"

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

    // TODO: Start here next week
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        { _gameObjects.push_back(objectFactory->TestCreateBrick(i * 50.f, j * 20.f, sf::Color::Red)); }
    }
}
