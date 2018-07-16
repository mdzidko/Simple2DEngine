#include <iostream>
#include <GSMLoaderImpl.h>
#include <AnimationsLoaderImpl.h>
#include <LuaTexturesLoader.h>

#include "Engine.h"
#include "WindowLoaderImpl.h"

int main()
{
	LuaTexturesLoader txLoader("resources/scripts/textures.lua");
	AnimationsLoaderImpl anmLoader;
	WindowLoaderImpl winLoader;
	GSMLoaderImpl gsLoader;

	Engine engine;

	//Run
	engine.Init(&winLoader, &gsLoader, &txLoader, &anmLoader);
	engine.Run();

	system("PAUSE");
}