#pragma once

#include <memory>
#include "Object.h"
#include "SFML/Graphics.hpp"

namespace Breakout
{
    class ObjectFactory
    {
      public:
        ObjectFactory();
        ~ObjectFactory();

        std::shared_ptr<Object> CreateObject() {}

        // temp create brick function
        std::shared_ptr<Object> TestCreateBrick(float x, float y, sf::Color color);
    };
}  // namespace Breakout
