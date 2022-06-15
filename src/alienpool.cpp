#include "../include/alienpool.h"

void alienpool::getAlien(sf::Vector2f const& origin)
{
    for(auto i = 0; i < this->size(); ++i)
    {
        if(!this->at(i).isActive())
        {
            this->at(i).reset(origin);
            return;
        }
    }
}

void alienpool::move()
{
    for(auto i = 0; i < this->size(); ++i)
    {
        this->at(i).move();
    }
}
