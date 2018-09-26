#pragma once

namespace sf
{
    class RenderWindow;
}

namespace Breakout
{
    class RenderSystem
    {
      public:
        RenderSystem(sf::RenderWindow window);
        ~RenderSystem() = default;

        void Update(float deltaTime);

      protected:
    };
}  // namespace Breakout
