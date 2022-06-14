#pragma once

#include <SFML/Graphics.hpp>

class alien : public sf::CircleShape
{
public:
    alien();
    ~alien() = default;
    
    void move();
private:
};
