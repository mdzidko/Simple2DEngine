#include "GameStateMachine.h"


GameStateMachine::GameStateMachine(Context context)
{
    gameContext = context;
}


void GameStateMachine::Update(int updateTime)
{
	if (!states.empty())
	{
		auto currentState = states.top().get();
		currentState->Update(this, updateTime);
	}
};

void GameStateMachine::Render(float interpolation)
{
	if (!states.empty())
	{
		auto currentState = states.top().get();
		currentState->Render(interpolation);
	}
};

void GameStateMachine::Push(GameStatePtr state)
{
    states.push(std::move(state));
};

void GameStateMachine::Pop()
{
	states.pop();
};

bool GameStateMachine::IsEmpty()
{
	return states.empty();
}

void GameStateMachine::LoadWorld(WorldLoader* worldLoader)
{
	if (!states.empty())
	{
		auto currentState = states.top().get();
		currentState->LoadWorld(worldLoader);
	}
}

Context GameStateMachine::GetContext() {
    return gameContext;
}