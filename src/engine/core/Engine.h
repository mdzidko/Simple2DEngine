#pragma once

#include <memory>
#include "TexturesLoader.h"
#include "GameStateMachine.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "WindowLoader.h"
#include "GSMLoader.h"
#include "ResourceHolder.h"

typedef float FrameTime;

const int UPDATES_PER_SECOND = 25;
const int UPDATE_TIME = 1000 / UPDATES_PER_SECOND;

class Engine
{
public:
    void Init(WindowLoader* winLoader, GSMLoader* gsLoader, TexturesLoader* texturesLoader);
	void Run();

private:
    GameStateMachinePtr states;
    WindowPtr mainWindow;
    TexturesHolder texturesHolder;

	void LoadTextures(TexturesLoader* texturesLoader);
	void LoadWindow(WindowLoader* winLoader);
    void LoadGameStates(GSMLoader* gsLoader);

	void ProcessEvents();
};

