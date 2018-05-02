#pragma once

#include <World.h>
#include "Context.h"

class WorldLoader
{
public:
    virtual WorldPtr Load(Context context, GameState* gameState) = 0;
};
