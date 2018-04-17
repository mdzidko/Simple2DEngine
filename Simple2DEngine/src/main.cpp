#include <iostream>
#include <factories/TexturesLoaderImpl.h>
#include <factories/GSMLoaderImpl.h>
#include "core/Engine.h"
#include "factories/WindowLoaderImpl.h"

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