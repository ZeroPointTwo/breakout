#include "Engine.h"
#include "Util.h"
#include "clock.h"

extern std::vector<nlohmann::json> g_traces;

Breakout::Engine::Engine(sf::RenderWindow* window)
{
    renderSystem  = std::make_unique<RenderSystem>(window);
    inputSystem   = std::make_unique<InputSystem>();
    physicsSystem = std::make_unique<PhysicsSystem>();
}

void Breakout::Engine::Update(float deltaTime, const std::vector<std::shared_ptr<Object>>& gameObjects)
{
    if (renderSystem != nullptr)
    {
        // please don't compress me
        renderSystem->Update(deltaTime, gameObjects);
    }

    // bad formating is bad
    if (inputSystem != nullptr)
    {
        inputSystem->Update(gameObjects);
    }

    if (physicsSystem != nullptr)
    {
        physicsSystem->Update(deltaTime, gameObjects);
    }
}
