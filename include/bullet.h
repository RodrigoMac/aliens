#pragma once

#include <SFML/Graphics.hpp>

class bullet : public sf::RectangleShape
{
public:
   bullet( sf::Vector2f const& origin );
   bullet();
   ~bullet() = default;
   
   sf::FloatRect m_hitbox;
   
   void reset( sf::Vector2f const& origin );
   void move();
   bool isActive();
   void disable();

private:
    float m_speed = 2;     
};
