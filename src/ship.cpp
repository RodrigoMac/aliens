#include "../include/ship.h"

ship::ship()
{
   m_speed = 0;

   this->setPointCount( 8 );
   this->setPoint( 0, sf::Vector2f( 0.f, -40.f ) );
   this->setPoint( 1, sf::Vector2f( -15.f, 20.f ) );
   this->setPoint( 2, sf::Vector2f( 30.f, 0.f ) );
   this->setPoint( 3, sf::Vector2f( 30.f, 10.f ) );
   this->setPoint( 4, sf::Vector2f( 0.f, 0.f ) );
   this->setPoint( 5, sf::Vector2f( -30.f, 10.f ) );
   this->setPoint( 6, sf::Vector2f( -30.f, 0.f ) );
   this->setPoint( 7, sf::Vector2f( 15.f, 20.f ) );

   this->setPosition( 400, 750 );
   this->setOrigin( 0.f, -15.f );
}

void ship::move()
{
   this->sf::Shape::move( m_speed, 0 );
}

void ship::setSpeed( float const& speed )
{
   m_speed += speed;
}
