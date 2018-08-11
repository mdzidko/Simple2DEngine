#pragma once

#include <memory>
#include "ResourcesLoader.h"
#include "GameStateContext.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "WindowLoader.h"
#include "GSMLoader.h"
#include "ResourceHolder.h"

typedef float FrameTime;

const int UPDATES_PER_SECOND = 25;
const int UPDATE_TIME = 1000 / UPDATES_PER_SECOND;

class GameLoop
{
public:
	GameLoop(GameStateContext* gsm, sf::RenderWindow* renderWindow);

	void Run();

private:
	sf::RenderWindow* renderWindow;
    GameStateContext* stateMachine;

	void ProcessWindowEvents();
};