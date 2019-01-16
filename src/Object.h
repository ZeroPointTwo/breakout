#pragma once

#include <vector>
#include "Component.h"

namespace Breakout
{
    class Object
    {
      public:
        Object();
        virtual ~Object() = default;

        template<typename T>
        T* GetComponent() const
        {
            T* ret = nullptr;

            for (auto& compIter : components)
            {
                if (auto component = dynamic_cast<T*>(compIter.get()))
                {
                    ret = component;
                    break;
                }
            }

            return ret;
        }

        void AddComponent(std::shared_ptr<BaseComponent> component);
        void Update(float deltaTime);
       
      protected:
        std::vector<std::shared_ptr<BaseComponent>> components;
    };
}  // namespace Breakout
