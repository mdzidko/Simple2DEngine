#pragma once

#include <string>
#include <World.h>

class Context;

class EntityFactory
{
public:
    virtual void Create(World* _world, std::string _objectName, sf::Vector2f pos) = 0;
};


