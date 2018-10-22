#pragma once
#include "Object.h"

namespace sf
{
    class RenderWindow;
}

namespace Breakout
{
    class RenderSystem
    {
      public:
        RenderSystem(sf::RenderWindow* _window);
        ~RenderSystem() = default;

        void Update(float deltaTime, const std::vector<std::shared_ptr<Object>>& gameObjects);

      protected:
        sf::RenderWindow* window;
    };
}  // namespace Breakout
