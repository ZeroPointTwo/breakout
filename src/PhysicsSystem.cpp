#include "PhysicsSystem.h"
#include "Object.h"
#include "Util.h"

Breakout::PhysicsSystem::PhysicsSystem()
{
}

void Breakout::PhysicsSystem::Update(float deltaTime, const std::vector<std::shared_ptr<Object>>& gameObjects)
{
    // get components of type
    UNUSED_ARGS(deltaTime, gameObjects);

    for (auto& object : gameObjects)
    {
        Assert(object != nullptr, "Invalid game object.");

        auto movementComponent = object->GetComponent<MovementComponent>();
        auto positionComponent = object->GetComponent<PositionComponent>();

        if (!movementComponent || !positionComponent)
        {
            continue;
        }

        // If no velocity, continue
        auto velocity = movementComponent->GetVelocity();
        if (velocity.x != 0.f || velocity.y != 0.f)
        {
            // Check of for collisions
            bool isCollided = false;
            if (auto collisionComponent = object->GetComponent<CollisionComponent>())
            {
                // (TODO: channels)
                for (auto& otherObject : gameObjects)
                {
                    // Dont compare against current object
                    if (object == otherObject)
                    {
                        continue;
                    }

                    // Get other object collision comp
                    if (auto otherCollisionComp = otherObject->GetComponent<CollisionComponent>())
                    {
                        if (collisionComponent->Intersects(otherCollisionComp))
                        {
                            isCollided = true;
                            break;
                        }
                    }
                }
                // If cant move, dont
                // Fire collision reaction on both objects
            }

            // Move if we havent collided
            if (!isCollided)
            {
                auto newPos = positionComponent->GetPosition() + (velocity * deltaTime);
                positionComponent->SetPosition(newPos);
            }
            // TODO collision response!
        }
    }
}
