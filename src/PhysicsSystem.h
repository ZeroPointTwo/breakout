#pragma once
#include "Object.h"

namespace Breakout
{
    class PhysicsSystem
    {
      public:
        PhysicsSystem();
        ~PhysicsSystem() = default;

        void Update(float deltaTime, const std::vector<std::shared_ptr<Object>>& gameObjects);
    };
}  // namespace Breakout
