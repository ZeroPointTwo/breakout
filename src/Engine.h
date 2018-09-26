#pragma once
#include "RenderSystem.h"
#include "SFML/Graphics.hpp"

#include <memory>

namespace Breakout
{
    class Engine
    {
      public:
        Engine(sf::RenderWindow* window);
        ~Engine();

        void Update(float deltaTime);

        std::unique_ptr<RenderSystem> renderSystem;
    };
}  // namespace Breakout
