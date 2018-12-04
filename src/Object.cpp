#include "Object.h"
#include "Util.h"

using Breakout::Object;

Object::Object()
{
}

Breakout::BaseComponent* Breakout::Object::GetComponent(EComponentType type) const
{
    BaseComponent* ret = nullptr;

    for (auto& compIter : components)
    {
        auto compType = compIter->GetType();
        Assert(compType != CT_INVALID, "Component type not set - :( ");

        if (compType == type)
        {
            ret = compIter.get();
            break;
        }
    }

    return ret;
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
