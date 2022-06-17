#include "../include/alienpool.h"

void alienpool::getAlien(sf::Vector2f const& origin, int const& pattern)
{
    for(auto i = 0; i < this->size(); ++i)
    {
        if(!this->at(i).isActive())
        {
            this->at(i).reset(origin, pattern);
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
