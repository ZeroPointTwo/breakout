#include "Game.h"

bool Breakout::BreakoutGame::Init(std::shared_ptr<sf::RenderWindow>& sfWindow)
{
    bool isSuccess = false;

    _sfWindow = sfWindow;

    // do something

    return isSuccess;
}

void Breakout::BreakoutGame::BeginGame()
{
    EndGame();
    Init(_sfWindow);
}
