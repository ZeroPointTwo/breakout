#include "RenderSystem.h"
#include "Util.h"
#include "Object.h"

#include "SFML/Graphics.hpp"

Breakout::RenderSystem::RenderSystem(sf::RenderWindow* _window) :
window(_window)
{
}

void Breakout::RenderSystem::Update(float deltaTime, const std::vector<Object>& gameObjects)
{
    // get components of type
    UNUSED_ARGS(deltaTime);

    // TODO Render here
    for (auto& object : gameObjects)
    {
        auto renderComponent = dynamic_cast<RenderComponent*>(object.GetComponent(CT_RENDERCOMPONENT));
            //->GetShape()
        
        window->draw(*renderComponent->GetShape());
    }
}