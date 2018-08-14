#include <iostream>

#include "SDL2/SDL.h"  // NOLINT

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
  fmt::print(std::forward<T>(args)...);  // NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)
}

// screen dimension constants
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window*   gWindow   = nullptr;
SDL_Renderer* gRenderer = nullptr;

// initialize sdl
bool init()
{
  // result of initialization
  bool success = true;

  Message("Print {}\n", 10);
  for (auto i = 0; i < 5; ++i) { Assert(false, "Print {}\n", 10); }

  // Intialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    fmt::print("SDL could not initialize! error: {}\n", SDL_GetError());
    success = false;
  }
  else
  {
    // create window
    gWindow = SDL_CreateWindow(
        "SDL Skeleton", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

    if (gWindow == nullptr)
    {
      fmt::print("Window could not be created! error: {}\n", SDL_GetError());
      success = false;
    }
    else
    {
      // create renderer for window
      gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

      if (gRenderer == nullptr)
      {
        fmt::print("Renderer could not be created! error: {}\n", SDL_GetError());
        success = false;
      }
      else
      {
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);  // RGBA
      }
    }
  }

  return success;
}

void close()
{
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  gRenderer = nullptr;
  gWindow   = nullptr;

  SDL_Quit();
}

int main(int argc, char* argv[])
{
  UNUSED_ARGS(argc, argv);

  if (!init()) { fmt::print("Failed to initialize!\n"); }
  else
  {
    bool quit = false;

    SDL_Event e;

    while (!quit)
    {
      // handle event on queue
      while (SDL_PollEvent(&e) != 0)
      {
        // user request to quit
        if (e.type == SDL_QUIT) { quit = true; }

        // clear screen
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
        SDL_RenderClear(gRenderer);

        auto r = SDL_Rect{100, 100, 200, 200};

        SDL_SetRenderDrawColor(gRenderer, 0, 0, 128, 0);
        SDL_RenderFillRect(gRenderer, &r);

        // update screen
        SDL_RenderPresent(gRenderer);
      }
    }
  }

  close();

  return 0;
}
