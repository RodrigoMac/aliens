#pragma once

#include "../include/alien.h"

#include <SFML/Graphics.hpp>
#include <array>

class alienpool : public std::array<alien, 20>
{
public:
    alienpool() = default;
    ~alienpool() = default;
    
    void getAlien(sf::Vector2f const& origin, int const& pattern);
    void move();
};
