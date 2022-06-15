//g++ main.cpp ship.cpp bullet.cpp bulletpool.cpp alien.cpp alienpool.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system -lpthread

//usar chrono?

#include "../include/main.h"

#include <X11/Xlib.h>
#include <iostream>
#include <unistd.h>

#define msleep( n ) usleep( n * 1000 );

game::game()
{
   m_window.create( sf::VideoMode( 800, 800 ), "Aliens" );
   m_window.setKeyRepeatEnabled( false );

   timer = clock.now();

   m_aliens.getAlien( sf::Vector2f( 40, 40 ) );
   m_aliens.getAlien( sf::Vector2f( 40, 120 ) );
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

      m_aliens.move();
      for( auto i = 0; i < m_aliens.size(); ++i )
      {
         m_window.draw( m_aliens[ i ] );
      }

      m_window.display();
   }

   msleep( 1 );
}

void game::inputHandler()
{
   bool holdfire = false;
   while( m_window.isOpen() )
   {
      if( m_window.pollEvent( m_event ) )
      {
         if( m_event.type == sf::Event::KeyPressed )
         {
            if( m_event.key.code == sf::Keyboard::A )
            {
               m_ship.setSpeed( -0.5 );
            }
            else if( m_event.key.code == sf::Keyboard::D )
            {
               m_ship.setSpeed( 0.5 );
            }
            else if( m_event.key.code == sf::Keyboard::Space )
            {
               holdfire = true;
               timer = clock.now();
               //m_bullets.getBullet( m_ship.getPosition() );
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
               m_ship.setSpeed( 0.5 );
            }
            else if( m_event.key.code == sf::Keyboard::D )
            {
               m_ship.setSpeed( -0.5 );
            }
            else if( m_event.key.code == sf::Keyboard::Space )
            {
               holdfire = false;
            }
         }
      }

      if( holdfire && (std::chrono::duration_cast< std::chrono::duration< int, std::milli > >( std::chrono::high_resolution_clock::now() - timer )).count() > 50)
      {
         m_bullets.getBullet( m_ship.getPosition() );
         timer = clock.now();
      }

      msleep( 1 );
   }
}

void game::hitDetection()
{
   while( m_window.isOpen() )
   {
      for( auto i = 0; i < m_bullets.size(); ++i )
      {
         for( auto j = 0; j < m_aliens.size(); j++ )
         {
            if( m_bullets[ i ].m_hitbox.intersects( m_aliens[ j ].m_hitbox ) )
            {
               m_bullets[ i ].disable();
               m_aliens[ j ].disable();
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
   XInitThreads();

   game session;

   std::thread screen( &game::renderFrame, std::ref( session ) );
   screen.detach();
   std::thread input( &game::inputHandler, std::ref( session ) );
   input.detach();
   std::thread collision( &game::hitDetection, std::ref( session ) );
   collision.detach();

   while( session.active() )
   {
      msleep( 1 );
   }

   return 0;
}
