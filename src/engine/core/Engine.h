#pragma once

#include <memory>
#include "ResourcesLoader.h"
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
    void Init(WindowLoader* winLoader, GSMLoader* gsLoader, TexturesLoader* texturesLoader, AnimationsLoader* animationsLoader);
	void Run();

private:
    GameStateMachinePtr states;
    WindowPtr mainWindow;
    TexturesHolder texturesHolder;
	AnimationsHolder animationsHolder;

	void LoadTextures(TexturesLoader* texturesLoader);
	void LoadAnimations(AnimationsLoader* animationsLoader);
	void LoadWindow(WindowLoader* winLoader);
    void LoadGameStates(GSMLoader* gsLoader);

	void ProcessEvents();
};

