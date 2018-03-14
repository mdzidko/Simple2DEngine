#include "Engine.h"
#include <chrono>
#include <iostream>
#include "SFML\Window\Event.hpp"


Engine::Engine(std::unique_ptr<sf::RenderWindow> window, std::unique_ptr<GameStateMachine> stateMachine)
{
	mainWindow = std::move(window);
	states = std::move(stateMachine);
}


void Engine::Run()
{
	auto prevTime(std::chrono::high_resolution_clock::now());
	FrameTime lag{ 0.0 };

	while(!states->IsEmpty() && mainWindow->isOpen())
	{
		auto currentTime(std::chrono::high_resolution_clock::now());
		auto elapsedTime(currentTime - prevTime);
		prevTime = currentTime;
		FrameTime frameTime{ std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(elapsedTime).count() };

		lag += frameTime;

		ProcessEvents();

		while (lag >= UPDATE_TIME)
		{
			lag -= UPDATE_TIME;
			states->Update(UPDATE_TIME);
		}

		float interpolation = lag / UPDATE_TIME;

		states->Render(mainWindow.get(), interpolation);
	}
}

void Engine::ProcessEvents()
{
	sf::Event event;
	while (mainWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mainWindow->close();
	}
}
