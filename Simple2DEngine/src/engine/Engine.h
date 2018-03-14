#pragma once

#include <memory>
#include "GameStateMachine.h"
#include "SFML\Graphics\RenderWindow.hpp"

typedef float FrameTime;

const int UPDATES_PER_SECOND = 25;
const int UPDATE_TIME = 1000 / UPDATES_PER_SECOND;

class Engine
{
public:
	Engine(std::unique_ptr<sf::RenderWindow> window, std::unique_ptr<GameStateMachine> stateMachine);

	void Run();
private:
	std::unique_ptr<GameStateMachine> states;
	std::unique_ptr<sf::RenderWindow> mainWindow;


	void ProcessEvents();
};

