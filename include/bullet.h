#pragma once

#include <SFML/Graphics.hpp>

class bullet : public sf::RectangleShape
{
public:
   bullet( sf::Vector2f origin );
   bullet();
   ~bullet() = default;

   void reset( sf::Vector2f origin );
   void move();
   bool isActive();
   void disable();

private:
    float m_speed = 2;
};
