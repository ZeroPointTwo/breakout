#pragma once
#include <memory>
#include <vector>

namespace sf
{
    class RenderWindow;
}

namespace Breakout
{
    class Object;

    struct GameInputs
    {
        bool moveLeft;
        bool moveRight;
        bool action;
        bool exit;
    };

    class InputSystem
    {
      public:
        InputSystem();
        ~InputSystem() = default;

        void Update(const std::vector<std::shared_ptr<Object>>& gameObjects);

        GameInputs GetCurrentInputs() const
        {
            return currentInputs;
        }

      protected:
        GameInputs currentInputs;

        void UpdateInputs();
    };
}  // namespace Breakout
