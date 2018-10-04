#include <iostream>

#include "Engine.h"
#include "Game.h"
#include "SFML/Graphics.hpp"
#include "Util.h"

// screen dimension constants
const int   SCREEN_WIDTH  = 640;
const int   SCREEN_HEIGHT = 480;
const char* WINDOW_TITLE  = "Breakout";

class IApplication
{
  public:
    virtual ~IApplication() {}
    virtual bool Init()     = 0;
    virtual void Run()      = 0;
    virtual void Shutdown() = 0;
};

class GameApplication : public IApplication
{
  public:
    GameApplication(std::shared_ptr<Breakout::Game> inGame);
    virtual ~GameApplication() {}

    // Create window and game
    bool Init() override;

    void Run() override;
    void Shutdown() override;

  private:
    std::shared_ptr<Breakout::Engine> engine;
    std::shared_ptr<Breakout::Game>   game;
    std::shared_ptr<sf::RenderWindow> mainWindow;
};

int main(int argc, char* argv[])
{
    UNUSED_ARGS(argc, argv);

    // THat other way
    // std::shared_ptr<Breakout::BreakoutGame> game = std::make_shared<Breakout::BreakoutGame>();
    // GameApplication                         appTwo(game);

    // Move constructor
    GameApplication app(std::make_shared<Breakout::BreakoutGame>());

    if (!app.Init())
    {
        fmt::print("Failed to initialize!\n");
        return -1;
    }

    app.Run();
    app.Shutdown();

    return 0;
}

GameApplication::GameApplication(std::shared_ptr<Breakout::Game> inGame) : game(inGame) {}

bool GameApplication::Init()
{
    mainWindow = std::shared_ptr<sf::RenderWindow>(
        new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), sf::String(WINDOW_TITLE)));

    // engine = std::shared_ptr<Breakout::Engine>(new Breakout::Engine(mainWindow));

    return true;
}

void GameApplication::Run()
{
    sf::CircleShape testCircle(1.f);  // Create circle of radius 1
    testCircle.setScale(
        sf::Vector2f(static_cast<float>(SCREEN_WIDTH) * 0.5f,
                     static_cast<float>(SCREEN_HEIGHT) * 0.5f));  // Scale the circle to make an ellipses
    testCircle.setFillColor(sf::Color::Green);

    while (mainWindow->isOpen())
    {
        sf::Event sfEvent = {};
        while (mainWindow->pollEvent(sfEvent))
        {
            if (sfEvent.type == sf::Event::Closed) { mainWindow->close(); }
        }

        mainWindow->clear();  // Remove all drawn content from window
        mainWindow->draw(testCircle);
        mainWindow->display();  // Present the window
    }
}

void GameApplication::Shutdown() {}
