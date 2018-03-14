#include "GameStateMachine.h"

void GameStateMachine::Update(int updateTime)
{
	if (!states.empty())
	{
		auto currentState = states.top().get();
		currentState->Update(this, updateTime);
	}
};

void GameStateMachine::Render(sf::RenderWindow* window, float interpolation)
{
	if (!states.empty())
	{
		auto currentState = states.top().get();
		currentState->Render(window, interpolation);
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
