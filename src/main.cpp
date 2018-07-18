#include <iostream>
#include <GSMLoaderImpl.h>
#include <LuaResourcesLoader.h>

#include "Engine.h"
#include "WindowLoaderImpl.h"

int main()
{
    LuaResourcesLoader<sf::Texture> txLoader("resources/scripts/resources.lua",  "textures");
    LuaResourcesLoader<Animation> anmLoader("resources/scripts/resources.lua", "animations");
	WindowLoaderImpl winLoader;
	GSMLoaderImpl gsLoader;

	Engine engine;

	//Run
	engine.Init(&winLoader, &gsLoader, &txLoader, &anmLoader);
	engine.Run();

	system("PAUSE");
}