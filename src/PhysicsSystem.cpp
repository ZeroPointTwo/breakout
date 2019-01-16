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

    // TODO : PICKUP HERE
    // Add comment here about adding physics system
    // Good luck - WWJD
    for (auto& object : gameObjects)
    {
        Assert(object != nullptr, "Invalid game object.");

        auto collisionComponent = object->GetComponent<CollisionComponent>();
        auto movementComponent = object->GetComponent<MovementComponent>();
        collisionComponent; // just making sure that things work
        movementComponent;
        
        // If no velocity, continue
//        if(movementComponent->)
        // Pre-Check against other objects (TODO: channels)
        // If cant move, dont
        // Fire collision reaction on both objects
    }
}
