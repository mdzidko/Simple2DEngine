#include "GameStateContext.h"


GameStateContext::GameStateContext(WorldFactory* worldLoader)
{
	this->worldFactory = worldLoader;
}


void GameStateContext::Update(int updateTime)
{
	if (!states.empty())
	{
		auto currentState = states.top().get();
		currentState->Update(updateTime);
	}
};

void GameStateContext::Render(float interpolation)
{
	if (!states.empty())
	{
		auto currentState = states.top().get();
		currentState->Render(interpolation);
	}
};

void GameStateContext::Push(GameStatePtr state)
{
    states.push(std::move(state));
};

void GameStateContext::Pop()
{
	states.pop();
};

bool GameStateContext::IsEmpty()
{
	return states.empty();
}

void GameStateContext::LoadWorld(const std::string worldName)
{
    if (!IsEmpty())
    {
        auto currentState = states.top().get();
        worldFactory->Load(worldName, currentState, entityFactory);
    }
}

void GameStateContext::LoadEntity(const std::string entityName, sf::Vector2f pos)
{
    if (!IsEmpty())
    {
        auto currentWorld = states.top().get()->getWorld();
        entityFactory->Create(currentWorld, entityName, pos);
    }
}