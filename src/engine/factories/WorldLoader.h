#pragma once

#include <World.h>
#include "Context.h"
#include "EntityFactory.h"

class WorldLoader
{
public:
    virtual WorldPtr Load(Context context, GameState* gameState) = 0;

protected:
    std::unique_ptr<EntityFactory> entityFactory;
};
