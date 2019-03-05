#include "Math.h"

namespace Breakout
{
    sf::Vector2f operator* (const sf::Vector2f& a, const sf::Vector2f& b)
    {
        return sf::Vector2f(a.x * b.x, a.y * b.y);
    }
}
