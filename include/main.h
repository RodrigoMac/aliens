#pragma once

#include "../include/alien.h"
#include "../include/alienpool.h"
#include "../include/bullet.h"
#include "../include/bulletpool.h"
#include "../include/ship.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <deque>
#include <thread>
#include <chrono>

class game
{
public:
    game();
    ~game() = default;
    
    bool active();
    void renderFrame();
    void inputHandler();
    void hitDetection();
    void fire(bool const& holdfire);
    
private:
    sf::RenderWindow m_window;
    sf::Event m_event;
    ship m_ship;
    bulletpool m_bullets;
    alienpool m_aliens;
    std::chrono::high_resolution_clock clock;
    std::chrono::high_resolution_clock::time_point timer;
};
