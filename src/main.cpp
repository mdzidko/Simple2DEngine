#include <iostream>
#include <GSMLoaderImpl.h>
#include <PlayingStateFactory.h>
#include "lua/factories/LuaResourcesLoader.h"

#include "GameLoop.h"
#include "WindowLoaderImpl.h"
#include "lua/factories/LuaEntityFactory.h"
#include "lua/factories/LuaWorldFactory.h"

int main()
{
    LuaHandler luaHandle("resources/scripts/main.lua");

    TexturesHolder txHolder;
    LuaResourcesLoader<sf::Texture> txLoader("textures", &luaHandle);
    txLoader.Load(txHolder);

    AnimationsHolder anmHolder;
    LuaResourcesLoader<Animation> anmLoader("animations", &luaHandle);
    anmLoader.Load(anmHolder);

    WindowLoaderImpl windowLoader;
    WindowPtr renderWindow = windowLoader.Load();

    LuaEntityFactory entityFactory(&txHolder, &anmHolder, &luaHandle);
    LuaWorldFactory worldLoader(&luaHandle, renderWindow.get());

    GameStateContext gameStateContext(&worldLoader, &entityFactory);

    //------------------------------------------------------
    PlayingStateFactory stateFactory;

    gameStateContext.Push(stateFactory.Create(&gameStateContext));
    gameStateContext.LoadWorld("base_world");

    /*GameApi gameApi;

    LuaRef luaMain = luaHandle.GetLuaGlobal("main");
    luaMain(gameApi);*/

    //------------------------------------------------------

	GameLoop loop(&gameStateContext, renderWindow.get());
	loop.Run();
}