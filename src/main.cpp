#include <iostream>
#include <TexturesLoaderImpl.h>
#include <GSMLoaderImpl.h>
#include <AnimationsLoaderImpl.h>

#include "Engine.h"
#include "WindowLoaderImpl.h"

int main()
{
	TexturesLoaderImpl txLoader;
	AnimationsLoaderImpl anmLoader;
	WindowLoaderImpl winLoader;
	GSMLoaderImpl gsLoader;

	Engine engine;

	//Run
	engine.Init(&winLoader, &gsLoader, &txLoader, &anmLoader);
	engine.Run();

	system("PAUSE");
}