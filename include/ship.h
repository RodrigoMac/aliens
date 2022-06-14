#pragma once

#include <SFML/Graphics.hpp>

class ship : public sf::ConvexShape
{
public:
    ship();
    ~ship() = default;
    
    void move();
    void setSpeed(float const& speed);
    void shoot();
    
private:
    float m_speed;
};
