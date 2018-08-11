#pragma once

#include <ResourceHolder.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <EntityFactory.h>
#include "../../lua/core/LuaHandler.h"
#include "GameStateContext.h"

class WorldFactory;

class GameStateContext;

struct Context
{
    GameStateContext* gameStateMachine;
    sf::RenderWindow* renderWindow;
    TexturesHolder* texturesHolder;
    AnimationsHolder* animationsHolder;
    WorldFactory* worldLoader;
    EntityFactory* entityLoader;
};
