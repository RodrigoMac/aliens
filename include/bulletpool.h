#pragma once

#include "bullet.h"

#include <SFML/Graphics.hpp>
#include <array>


class bulletpool : public std::array<bullet, 20>
{
public:
    bulletpool() = default;
    ~bulletpool() = default;
    
//     static const int MAX_BULLETS = 20;
//     std::array<bullet, MAX_BULLETS> m_pool;
    
    void getBullet(sf::Vector2f origin);
    void move();
    
private:
};
