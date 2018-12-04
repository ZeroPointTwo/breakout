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

        std::shared_ptr<Object> CreateObject()
        {
        }

        // temp create brick function
        std::shared_ptr<Object> TestCreateBrick(float x, float y, float width, float height, sf::Color color);
        std::shared_ptr<Object> CreatePaddle(float     x,
                                             float     y,
                                             float     width,
                                             float     height,
                                             float     speed,
                                             float     boundLeft,
                                             float     boundRight,
                                             sf::Color color);
    };
}  // namespace Breakout
