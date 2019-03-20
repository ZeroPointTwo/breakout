#include "Math.h"

namespace Breakout
{
    sf::Vector2f operator* (const sf::Vector2f& a, const sf::Vector2f& b)
    {
        return sf::Vector2f(a.x * b.x, a.y * b.y);
    }

    float Dot(const sf::Vector2f& a, const sf::Vector2f& b)
    {
        return a.x * b.x + a.y * b.y;
    }

    sf::Vector2f Reflect(const sf::Vector2f& in, const sf::Vector2f& normal)
    {
        //v' = -2 * (v . n) * n + v;
        return (-2 * Dot(in, normal)) * normal + in;
    }
}
