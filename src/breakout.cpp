#include <iostream>

#include "Engine.h"
#include "Game.h"
#include "SFML/Graphics.hpp"
#include "Util.h"

// screen dimension constants
const int         SCREEN_WIDTH  = 640;
const int         SCREEN_HEIGHT = 480;
const char*       WINDOW_TITLE  = "Breakout";
sf::RenderWindow* MainWindow    = nullptr;

class IApplication
{
  public:
    virtual ~IApplication() {}
    virtual bool Init()     = 0;
    virtual void Update()   = 0;
    virtual void Shutdown() = 0;
};

class GameApplication : public IApplication
{
  public:
    GameApplication();
    ~GameApplication() {}

    // Create window and game
    bool Init() override;

    void Update() override;
    void Shutdown() override;

  private:
    std::shared_ptr<Breakout::Game>   game;
    std::shared_ptr<sf::RenderWindow> mainWindow;
};

// initialize sfml
bool init()
{
    // result of initialization
    bool success = true;

    Message("Print {}\n", 10);
    for (auto i = 0; i < 5; ++i) { Assert(true, "Print {}\n", 10); }

    MainWindow = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), sf::String(WINDOW_TITLE));

    // @! TODO START HERE - FIXME PLZ
    auto _Engine(Breakout::Engine(MainWindow));

    return success;
}

void Quit()
{
    if (MainWindow != nullptr)
    {
        delete MainWindow;
        MainWindow = nullptr;
    }
}

int main(int argc, char* argv[])
{
    UNUSED_ARGS(argc, argv);

    if (!init()) { fmt::print("Failed to initialize!\n"); }
    else
    {
        sf::CircleShape testCircle(1.f);  // Create circle of radius 1
        testCircle.setScale(
            sf::Vector2f(static_cast<float>(SCREEN_WIDTH) * 0.5f,
                         static_cast<float>(SCREEN_HEIGHT) * 0.5f));  // Scale the circle to make an ellipses
        testCircle.setFillColor(sf::Color::Green);

        while (MainWindow->isOpen())
        {
            sf::Event sfEvent = {};
            while (MainWindow->pollEvent(sfEvent))
            {
                if (sfEvent.type == sf::Event::Closed) { MainWindow->close(); }
            }

            MainWindow->clear();  // Remove all drawn content from window
            MainWindow->draw(testCircle);
            MainWindow->display();  // Present the window
        }
    }

    Quit();

    return 0;
}
