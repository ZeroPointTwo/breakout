#include "Game.h"
#include "Component.h"

bool Breakout::BreakoutGame::Init(std::shared_ptr<sf::RenderWindow>& sfWindow)
{
    bool isSuccess = false;

    _sfWindow = sfWindow;

    // do something
    Object testObject{};

    // Make a circle just because
    auto testCircle = std::make_shared<sf::CircleShape>(1.f);
    //sf::CircleShape testCircle(1.f);  // Create circle of radius 1
    testCircle->setScale(
        sf::Vector2f(static_cast<float>(50) * 0.5f,
            static_cast<float>(50) * 0.5f));  // Scale the circle to make an ellipses
    testCircle->setFillColor(sf::Color::Green);
    
    auto renderComponent = std::make_shared<RenderComponent>(testCircle);
    testObject.AddComponent(renderComponent);
    _gameObjects.push_back(testObject);

    return isSuccess;
}

void Breakout::BreakoutGame::BeginGame()
{
    EndGame();
    Init(_sfWindow);
}
