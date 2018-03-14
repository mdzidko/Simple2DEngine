#pragma once

#include <stack>
#include <memory>

#include "GameState.h"
#include "SFML\Graphics\RenderWindow.hpp"

class GameStateMachine
{
public:
	void Update(int updateTime);
	void Render(sf::RenderWindow* window, float interpolation);

	void Push(GameStatePtr state);
	void Pop();

	bool IsEmpty();

private:
	std::stack<GameStatePtr> states;
};

