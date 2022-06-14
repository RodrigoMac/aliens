#pragma once

#include "../include/alien.h"
#include "../include/bullet.h"
#include "../include/bulletpool.h"
#include "../include/ship.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <deque>
#include <thread>

class game
{
public:
    game();
    ~game() = default;
    
    bool active();
    void renderFrame();
    void inputHandler();
    
private:
    sf::RenderWindow m_window;
    sf::Event m_event;
    ship m_ship;
    bullet shot;
    bulletpool m_bullets;
    
    
};
