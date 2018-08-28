#include <iostream>

#include "SFML/Graphics.hpp"

#pragma warning(push)
#pragma warning(disable : 4127)
#include "fmt/format.h"  // NOLINT
#pragma warning(pop)

template<typename... T> void UNUSED_ARGS(T&&...) {}  // NOLINT(readability-named-parameter)

#if _DEBUG
namespace Debug
{
  template<typename... T> void Assert(bool condition, const char* str_condition, const char* format, T&&... args)
  {
    if (!condition)
    {
      auto message = fmt::format(format, std::forward<T>(args)...);
      fmt::print("Assertion: {} - {}\n", str_condition, message);
    }
  }

#define Assert(condition, message, ...)                         \
  if (!condition)                                               \
  {                                                             \
    static bool _local_enabled = true;                          \
    Debug::Assert(condition, #condition, message, __VA_ARGS__); \
    if (_local_enabled) { __debugbreak(); }                     \
  }
}  // namespace Debug
#else
#define Assert(...)
#endif

template<typename... T> void Message(T&&... args)
{
  fmt::print(
      std::forward<T>(args)...);  // NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay, hicpp-no-array-decay)
}

// screen dimension constants
const int         SCREEN_WIDTH  = 640;
const int         SCREEN_HEIGHT = 480;
const char*       WINDOW_TITLE  = "Breakout";
sf::RenderWindow* MainWindow    = nullptr;

// initialize sfml
bool init()
{
  // result of initialization
  bool success = true;

  Message("Print {}\n", 10);
  for (auto i = 0; i < 5; ++i) { Assert(false, "Print {}\n", 10); }

  MainWindow = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), sf::String(WINDOW_TITLE));

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
      sf::Event sfEvent;
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
