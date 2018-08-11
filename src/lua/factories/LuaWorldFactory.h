#pragma once

#include "WorldFactory.h"
#include "Context.h"
#include "../core/LuaHandler.h"

class LuaWorldFactory : public WorldFactory
{
public:
    LuaWorldFactory(LuaHandler* luaHandle, sf::RenderWindow* renderWindow);

    WorldPtr Load(const std::string& worldName, GameState* gameState, EntityFactory* entityFactory) override;

private:
    LuaHandler* luaHandle;
    sf::RenderWindow* renderWindow;
};
