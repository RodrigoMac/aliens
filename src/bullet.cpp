#include "../include/bullet.h"

bullet::bullet( sf::Vector2f origin )
{
   this->setSize( sf::Vector2f( 4.f, 16.f ) );
   this->setPosition( origin );
}

bullet::bullet()
{
   this->setSize( sf::Vector2f( 4.f, 16.f ) );
   this->setPosition( sf::Vector2f( -5, -5 ) );
}

void bullet::reset( sf::Vector2f origin )
{
   this->setPosition( origin );
}

void bullet::move()
{
   if( !isActive() )
      return;

   this->sf::Shape::move( 0, -m_speed );
}

bool bullet::isActive()
{
   return this->getPosition().y > -17;
}

void bullet::disable()
{
   this->setPosition( -5, -5 );
}
