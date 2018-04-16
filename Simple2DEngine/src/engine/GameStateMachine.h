#pragma once

#include <stack>
#include <memory>
#include "GameState.h"

using GameStateMachinePtr = std::unique_ptr<GameStateMachine>;

class GameStateMachine
{
public:
	void Update(int updateTime);
	void Render(float interpolation);

	void Push(GameStatePtr state);
	void Pop();

	bool IsEmpty();

private:
	std::stack<GameStatePtr> states;
};

