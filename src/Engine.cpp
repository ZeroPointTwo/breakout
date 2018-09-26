#include "Engine.h"
#include "Util.h"

Breakout::Engine::Engine(sf::RenderWindow* window)
{
    // renderSystem = RenderSystem(window);
    UNUSED_ARGS(window);
}

void Breakout::Engine::Update(float deltaTime)
{
    if (renderSystem != nullptr)
    {
        // please don't compress me
        renderSystem->Update(deltaTime);
    }
}
