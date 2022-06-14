#include "../include/bulletpool.h"

void bulletpool::getBullet(sf::Vector2f origin)
{
    for(auto i = 0; i < this->size(); ++i)
    {
        if( !this->at(i).isActive() )
        {
            this->at(i).reset( origin );
            return;
        }
    }
}

void bulletpool::move()
{
    for(auto i = 0; i < this->size(); ++i)
    {
        this->at(i).move();
    }
}
