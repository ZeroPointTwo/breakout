#pragma once
#include "Object.h"

namespace Breakout
{
    class CollisionSystem
    {
      public:
        CollisionSystem();
        ~CollisionSystem() = default;

        void Update(float deltaTime, const std::vector<std::shared_ptr<Object>>& gameObjects);
    };
}  // namespace Breakout
