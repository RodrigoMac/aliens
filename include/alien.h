#pragma once

#include <SFML/Graphics.hpp>

class alien : public sf::CircleShape
{
public:
    alien();
    ~alien() = default;
    
    sf::FloatRect m_hitbox;
    
    void reset(sf::Vector2f const& origin, int const& pattern);
    void move();
    bool isActive();
    void disable();
    void setPattern(int const& pattern);
    
private:
    float x_speed;
    float y_speed;
    float x_initial;
    float y_initial;
    float x_bound;
    float y_bound;
    
    
//     sf::FloatRect m_hitbox;
};
