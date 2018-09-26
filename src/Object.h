#ifndef BREAKOUT_OBJECT_H
#define BREAKOUT_OBJECT_H

#include <vector>
#include "Component.h"
#include "SDL2/SDL.h"

namespace Breakout
{
    class Object
    {
      public:
        Object();
        virtual ~Object() = default;

        BaseComponent* GetComponent(EComponentType type);

      protected:
        std::vector<std::shared_ptr<BaseComponent>> components;
    };
}  // namespace Breakout

#endif  // !BREAKOUT_OBJECT_HS
