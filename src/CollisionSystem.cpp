#include "CollisionSystem.h"
#include "Object.h"
#include "Util.h"

Breakout::CollisionSystem::CollisionSystem()
{
}

void Breakout::CollisionSystem::Update(float deltaTime, const std::vector<std::shared_ptr<Object>>& gameObjects)
{
    // get components of type
    UNUSED_ARGS(deltaTime, gameObjects);

    // TODO : PICKUP HERE
    // Add comment here about adding physics system
    // Good luck - WWJD
    for (auto& object : gameObjects)
    {
        Assert(object != nullptr, "Invalid game object.");

        auto collisionComponent = dynamic_cast<CollisionComponent*>(object->GetComponent(CT_COLLISIONCOMPONENT));

        // auto positionComponent  = dynamic_cast<PositionComponent*>(object->GetComponent(CT_POSITIONCOMPONENT));
        //

        // if (positionComponent != nullptr && renderComponent != nullptr)
        //{
        //    // Translate
        //     sf::Shape* translatedShape = renderComponent->GetShape();
        //     Assert(translatedShape != nullptr, "Failed to get renderComponent shape");

        //     translatedShape->setPosition(positionComponent->GetPosition());

        //     window->draw(*translatedShape);
        //}
    }
}
