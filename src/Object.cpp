#include "Object.h"

using Breakout::Object;

Object::Object() {}

Breakout::BaseComponent* Breakout::Object::GetComponent(EComponentType type)
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
