#pragma once

#include "WorldLoader.h"
#include "Context.h"
#include "../core/LuaHandler.h"

class LuaWorldLoader : public WorldLoader
{
public:
    LuaWorldLoader(std::string script);

    WorldPtr Load(Context context, GameState* gameState) override;

private:
    LuaHandler luaHandle;
};
