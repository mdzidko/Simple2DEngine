#pragma once

#include "WorldLoader.h"
#include "Context.h"

class LuaWorldLoader : public WorldLoader
{
public:
    WorldPtr Load(Context context, GameState* gameState) override;
};
