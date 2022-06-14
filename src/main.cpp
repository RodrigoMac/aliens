//g++ main.cpp ship.cpp bullet.cpp bulletpool.cpp alien.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system -lpthread

#include "../include/main.h"

#include <iostream>
#include <unistd.h>

#define msleep( n ) usleep( n * 1000 );

game::game()
{
   m_window.create( sf::VideoMode( 800, 800 ), "Aliens" );
   m_window.setKeyRepeatEnabled( false );
}

bool game::active()
{
    return m_window.isOpen();
}

void game::renderFrame()
{
   while( m_window.isOpen() )
   {
      m_window.clear();

      m_ship.move();
      m_window.draw( m_ship );

      m_bullets.move();
      for( auto i = 0; i < m_bullets.size(); ++i )
      {
         m_window.draw( m_bullets[ i ] );
      }
      
      m_window.draw(m_alien);

      m_window.display();
      msleep( 1 );
   }
}

void game::inputHandler()
{
   while( m_window.isOpen() )
   {
      if( m_window.pollEvent( m_event ) )
      {
         if( m_event.type == sf::Event::KeyPressed )
         {
            if( m_event.key.code == sf::Keyboard::A )
            {
               m_ship.setSpeed(-0.5);
            }
            else if( m_event.key.code == sf::Keyboard::D )
            {
               m_ship.setSpeed(0.5);
            }
            else if( m_event.key.code == sf::Keyboard::Space )
            {
               m_bullets.getBullet( m_ship.getPosition() );
            }
            else if( m_event.key.code == sf::Keyboard::Escape )
            {
               m_window.clear();
               m_window.setActive( false );
               m_window.close();
            }
         }
         else if( m_event.type == sf::Event::KeyReleased )
         {
            if( m_event.key.code == sf::Keyboard::A )
            {
               m_ship.setSpeed(0.5);
            }
            else if( m_event.key.code == sf::Keyboard::D )
            {
               m_ship.setSpeed(-0.5);
            }
         }
      }

      msleep( 1 );
   }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
   game session;

   std::thread screen( &game::renderFrame, std::ref( session ) );
   screen.detach();
   std::thread input( &game::inputHandler, std::ref( session ) );
   input.detach();

   while( session.active() )
   {
      msleep( 1 );
   }
   
   return 0;
}
