#pragma once

#include <stack>
#include <memory>
#include "GameState.h"

using GameStateMachinePtr = std::unique_ptr<GameStateMachine>;

class GameStateMachine
{
public:
    GameStateMachine(Context context);

	void Update(int updateTime);
	void Render(float interpolation);

	void Push(GameStatePtr state);
	void Pop();

	bool IsEmpty();

    void LoadWorld(WorldLoader* worldLoader);

    Context GetContext();
private:
	std::stack<GameStatePtr> states;
    Context gameContext;
};

