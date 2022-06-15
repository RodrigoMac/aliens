#include "../include/alien.h"


alien::alien()
{
    this->setOrigin(30,30);
    this->setRadius(30);
    this->setPointCount(8);
    this->setPosition(-65,-65);
}

void alien::reset(sf::Vector2f const& origin)
{
    this->setPosition(origin);
}

void alien::move()
{
    if (!this->isActive())
        return;
    
    if( this->getPosition().x < 50){
        m_speed = 0.25;
    }
    else if( this->getPosition().x > 750)
    {
        m_speed = -0.25;
    }
    
    this->sf::Shape::move(m_speed, 0);
    m_hitbox = this->getGlobalBounds();
}

bool alien::isActive()
{
    return this->getPosition().y > -60;
}

void alien::disable()
{
    this->setPosition(-65,-65);
    m_hitbox = this->getGlobalBounds();
}
