#pragma once

#include <string>
#include <World.h>

class Context;

class EntityFactory
{
public:
    virtual void Create(std::string _objectName, sf::Vector2f pos) = 0;

protected:
    World* world;
    Context* context;
};


