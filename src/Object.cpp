#include "Object.h"
#include "Util.h"

using Breakout::Object;

Object::Object()
{
}

void Breakout::Object::AddComponent(std::shared_ptr<BaseComponent> component)
{
    components.push_back(component);
}

void Breakout::Object::Update(float deltaTime)
{
    for (auto component : components)
    {
        component->Update(deltaTime);
    }
}
