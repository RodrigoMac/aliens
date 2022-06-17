#include "../include/alien.h"
#include "../include/movepattern.h"

alien::alien()
{
   this->setOrigin( 30, 30 );
   this->setRadius( 30 );
   this->setPointCount( 8 );
   this->setPosition( -65, -65 );
}

void alien::reset( sf::Vector2f const& origin, int const& pattern )
{
   this->setPosition( origin );

   x_initial = this->getPosition().x;
   y_initial = this->getPosition().y;
   setPattern( pattern );
}

void alien::move()
{
   if( !this->isActive() )
      return;

   if( this->getPosition().x < x_initial - x_bound )
   {
      x_speed = 0.25;
   }
   else if( this->getPosition().x > x_initial + x_bound )
   {
      x_speed = -0.25;
   }

   this->sf::Shape::move( x_speed, y_speed );
   m_hitbox = this->getGlobalBounds();
}

void alien::setPattern( int const& pattern )
{
   switch( pattern )
   {
      case STRAIGHT:
         x_speed = 0;
         y_speed = 0.1;
         x_bound = 1600;
         y_bound = 1600;
         break;
      case ZZLONG:
         x_speed = 0.25;
         y_speed = 0.1;
         x_bound = 400;
         y_bound = 1600;
         break;
      case ZZMEDIUM:
         x_speed = 0.25;
         y_speed = 0.1;
         x_bound = 200;
         y_bound = 1600;
         break;
      case ZZSHORT:
         x_speed = 0.25;
         y_speed = 0.1;
         x_bound = 100;
         y_bound = 1600;
         break;
   }
}

bool alien::isActive()
{
   return this->getPosition().y > -60;
}

void alien::disable()
{
   this->setPosition( -65, -65 );
   m_hitbox = this->getGlobalBounds();
}
