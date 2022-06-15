#pragma once

#include <SFML/Graphics.hpp>

class alien : public sf::CircleShape
{
public:
    alien();
    ~alien() = default;
    
    sf::FloatRect m_hitbox;
    
    void reset(sf::Vector2f const& origin);
    void move();
    bool isActive();
    void disable();
    
private:
    float m_speed;
//     sf::FloatRect m_hitbox;
};
