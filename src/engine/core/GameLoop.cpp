#include "GameLoop.h"
#include <chrono>

#include "SFML/Window/Event.hpp"

GameLoop::GameLoop(GameStateContext* gsm, sf::RenderWindow *renderWindow)
{
	this->renderWindow = renderWindow;
	this->stateMachine = gsm;
}

void GameLoop::Run()
{
	auto prevTime(std::chrono::high_resolution_clock::now());
	FrameTime lag{ 0.0 };



	while(!stateMachine->IsEmpty() && renderWindow->isOpen())
	{
		auto currentTime(std::chrono::high_resolution_clock::now());
		auto elapsedTime(currentTime - prevTime);
		prevTime = currentTime;
		FrameTime frameTime{ std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(elapsedTime).count() };

		lag += frameTime;

		ProcessWindowEvents();

		while (lag >= UPDATE_TIME)
		{
			lag -= UPDATE_TIME;

            stateMachine->Update(UPDATE_TIME);
		}

		float interpolation = lag / UPDATE_TIME;

        renderWindow->clear();
        stateMachine->Render(interpolation);
        renderWindow->display();
	}
}

void GameLoop::ProcessWindowEvents()
{
	sf::Event event;
	while (renderWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
            renderWindow->close();
	}
}

