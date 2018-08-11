#pragma once

#include <World.h>
#include "Context.h"
#include "EntityFactory.h"

class WorldFactory
{
public:
    virtual WorldPtr Load(const std::string& worldName, GameState* gameState, EntityFactory* entityFactory) = 0;
};
