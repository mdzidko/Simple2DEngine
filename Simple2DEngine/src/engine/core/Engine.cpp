#include "Engine.h"
#include <chrono>
#include <iostream>
#include "SFML/Window/Event.hpp"

void Engine::Init(WindowLoader* winLoader, GSMLoader* gsLoader, TexturesLoader* texturesLoader)
{
	LoadWindow(winLoader);
	LoadTextures(texturesLoader);
    LoadGameStates(gsLoader);
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

		states->Render(interpolation);
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

void Engine::LoadTextures(TexturesLoader* txLoader)
{
    txLoader->Load(texturesHolder);
}

void Engine::LoadWindow(WindowLoader *winLoader)
{
	mainWindow = std::move(winLoader->Load());
}

void Engine::LoadGameStates(GSMLoader *gsLoader)
{
    Context context{mainWindow.get(), &texturesHolder};
    states = std::move(gsLoader->Load(context));
}

