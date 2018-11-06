#include <iostream>

#include "Engine.h"
#include "Game.h"
#include "SFML/Graphics.hpp"
#include "Util.h"
#include "clock.h"

#include "nlohmann/json.hpp"

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
    GameApplication();
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

    GameApplication app;

    if (!app.Init())
    {
        fmt::print("Failed to initialize!\n");
        return -1;
    }

    app.Run();
    app.Shutdown();

    return 0;
}

GameApplication::GameApplication() {}

bool GameApplication::Init()
{
    auto app_config = R"(
    {
        "app_name": "Breakout",
        "width": 640,
        "height": 480
    }
    )"_json;

    std::string  app_name   = app_config["app_name"];
    std::int32_t app_width  = app_config["width"];
    std::int32_t app_height = app_config["height"];

    Assert(app_width > 0, "Invalid app_width: {}", app_width);
    Assert(app_height > 0, "Invalid app_height: {}", app_height);

    mainWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(app_width, app_height), sf::String(app_name));
    game       = std::make_shared<Breakout::BreakoutGame>();
    game->Init(mainWindow);
    engine = std::make_shared<Breakout::Engine>(mainWindow.get());

    return true;
}

void GameApplication::Run()
{
    /*sf::CircleShape testCircle(1.f);  // Create circle of radius 1
    testCircle.setScale(
        sf::Vector2f(static_cast<float>(SCREEN_WIDTH) * 0.5f,
                     static_cast<float>(SCREEN_HEIGHT) * 0.5f));  // Scale the circle to make an ellipses
    testCircle.setFillColor(sf::Color::Green);*/

    auto app_start_time = Time::GetTime();

    game->BeginGame();

    auto last_time     = Time::GetTime();
    auto fps_counter   = 0;
    auto seconds_timer = 0.0;

    const auto kFpsTarget       = 60;
    const auto kTargetFrameTime = 1.0 / kFpsTarget;

    while (mainWindow->isOpen())
    {
        auto current_time = Time::GetTime();
        auto elapsed_time = current_time - last_time;
        last_time         = current_time;

        seconds_timer += elapsed_time;

        Assert(elapsed_time >= 0.0,
               "Negative elapsed time: {} (current_time: {} last_time: {})",
               elapsed_time,
               current_time,
               last_time);

        // Report FPS
        if (seconds_timer >= 1.0)
        {
            Message("FPS: {}\n", fps_counter);

            fps_counter   = 0;
            seconds_timer = 0.0;
        }

        // Report frame time spikes
        if (elapsed_time > kTargetFrameTime)
        {
            Message("Warning @ {}s: Slow frame by {}s. (Elapsed: {}s Target: {}s)\n",
                    current_time - app_start_time,
                    elapsed_time - kTargetFrameTime,
                    elapsed_time,
                    kTargetFrameTime);
        }

        sf::Event sfEvent = {};
        while (mainWindow->pollEvent(sfEvent))
        {
            if (sfEvent.type == sf::Event::Closed) { mainWindow->close(); }
        }

        mainWindow->clear();  // Remove all drawn content from window

        engine->Update((float)elapsed_time, game->GetGameObjects());

        mainWindow->display();  // Present the window
        fps_counter++;
    }

    game->EndGame();
}

void GameApplication::Shutdown() {}
