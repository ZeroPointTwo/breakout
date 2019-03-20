#include "PhysicsSystem.h"
#include "CollisionReaction.h"
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
            // get old pos
            auto oldPos = positionComponent->GetPosition();

            // Move if we havent collided
            auto newPos = oldPos + (velocity * deltaTime);
            positionComponent->SetPosition(newPos);

            // Check of for collisions
            Hit hit;
            hit.isHit = false;
            if (auto collisionComponent = object->GetComponent<CollisionComponent>())
            {
                // (TODO: channels)
                std::shared_ptr<Object> collidedAgainst;
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
                        hit = collisionComponent->IntersectAABB(otherCollisionComp);
                        if (hit.isHit)
                        {
                            collidedAgainst = otherObject;
                            break;
                        }
                    }
                }

                // HACK- Technical debt (SJ) - we have collided set our selves back to the previous
                if (hit.isHit && collidedAgainst.get() != nullptr)
                {
                    Collision::CollisionReaction::CollisionReactionFunc reaction;
                    Collision::CollisionChannel channel = Collision::CollisionChannel::CC_NONE;
                    reactions.GetCollisionReaction(collisionComponent->ReadCollisionReaction(), channel, reaction);
                    if (reaction != nullptr)
                    {
                        reaction(channel, object.get(), collidedAgainst.get(), hit);
                    }

                    positionComponent->SetPosition(newPos - hit.delta);
                }
            }
        }
    }
}
