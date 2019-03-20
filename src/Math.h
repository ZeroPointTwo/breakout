#pragma once

#include "SFML/Graphics.hpp"

namespace Breakout
{
    struct AABB
    {
        sf::Vector2f pos;
        sf::Vector2f half;
    };

    struct Hit
    {
        sf::Vector2f pos;
        sf::Vector2f delta;
        sf::Vector2f normal;
        bool         isHit;

        Hit()
        {
            pos    = {0.f, 0.f};
            delta  = {0.f, 0.f};
            normal = {0.f, 0.f};
            isHit  = false;
        }
    };

    sf::Vector2f operator* (const sf::Vector2f& a, const sf::Vector2f& b);
    float        Dot(const sf::Vector2f& a, const sf::Vector2f& b);
    sf::Vector2f Reflect(const sf::Vector2f& in, const sf::Vector2f& normal);
}  // namespace Breakout
