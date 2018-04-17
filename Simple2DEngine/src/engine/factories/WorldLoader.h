#pragma once

#include <core/World.h>
#include "core/Context.h"

class WorldLoader
{
public:
    virtual WorldPtr Load(Context context, GameState* gameState) = 0;
};
