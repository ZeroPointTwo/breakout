#include "Engine.h"
#include "Util.h"

Breakout::Engine::Engine(sf::RenderWindow* window)
{
    renderSystem = std::make_unique<RenderSystem>(window);
}

void Breakout::Engine::Update(float deltaTime, const std::vector<Object>& gameObjects)
{
    if (renderSystem != nullptr)
    {
        // please don't compress me
        renderSystem->Update(deltaTime, gameObjects);
    }
}
