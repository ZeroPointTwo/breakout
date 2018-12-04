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

        BaseComponent* GetComponent(EComponentType type) const;

        void AddComponent(std::shared_ptr<BaseComponent> component);
        void Update(float deltaTime);

      protected:
        std::vector<std::shared_ptr<BaseComponent>> components;
    };
}  // namespace Breakout
