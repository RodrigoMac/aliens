#include "../include/bullet.h"

bullet::bullet( sf::Vector2f const& origin )
{
   this->setSize( sf::Vector2f( 4.f, 16.f ) );
   this->setPosition( origin );
}

bullet::bullet()
{
   this->setSize( sf::Vector2f( 4.f, 16.f ) );
   this->setPosition( sf::Vector2f( -20, -20 ) );
}

void bullet::reset( sf::Vector2f const& origin )
{
   this->setPosition( origin );
}

void bullet::move()
{
   if( !isActive() )
      return;

   this->sf::Shape::move( 0, -m_speed );
   m_hitbox = this->getGlobalBounds();
}

bool bullet::isActive()
{
   return this->getPosition().y > -17;
}

void bullet::disable()
{
   this->setPosition( -20, -20 );
   m_hitbox = this->getGlobalBounds();
}
