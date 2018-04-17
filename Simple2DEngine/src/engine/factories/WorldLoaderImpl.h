#pragma once

#include "WorldLoader.h"
#include "core/Context.h"

class WorldLoaderImpl : public WorldLoader
{
public:
    WorldPtr Load(Context context, GameState* gameState) override;

};
