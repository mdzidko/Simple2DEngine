#include <iostream>
#include <TexturesLoaderImpl.h>
#include <GSMLoaderImpl.h>
#include "Engine.h"
#include "WindowLoaderImpl.h"

int main()
{
	TexturesLoaderImpl txLoader;
	WindowLoaderImpl winLoader;
	GSMLoaderImpl gsLoader;

	Engine engine;

	//Run
	engine.Init(&winLoader, &gsLoader, &txLoader);
	engine.Run();

	system("PAUSE");
}