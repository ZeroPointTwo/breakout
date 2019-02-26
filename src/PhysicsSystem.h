#pragma once
#include "Object.h"
#include "CollisionReaction.h"

namespace Breakout
{
    class PhysicsSystem
    {
      public:
        PhysicsSystem();
        ~PhysicsSystem() = default;

        void Update(float deltaTime, const std::vector<std::shared_ptr<Object>>& gameObjects);

    protected:
        Collision::CollisionReaction reactions;
    };
}  // namespace Breakout
