#include "Object.h"

using Breakout::Object;

Object::Object() {}

Breakout::BaseComponent* Breakout::Object::GetComponent(EComponentType type) const
{
    BaseComponent* ret = nullptr;

    for (auto& compIter : components)
    {
        if (compIter->GetType() == type)
        {
            ret = compIter.get();
            break;
        }
    }

    return ret;
}

void Breakout::Object::AddComponent(std::shared_ptr<BaseComponent> component) { components.push_back(component); }
