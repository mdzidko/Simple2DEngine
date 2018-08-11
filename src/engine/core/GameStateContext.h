#pragma once

#include <stack>
#include <memory>
#include "GameState.h"

using GameStateMachinePtr = std::unique_ptr<GameStateContext>;

class GameStateContext
{
public:
    GameStateContext(WorldFactory* worldLoader, EntityFactory* entityFactory);

	void Update(int updateTime);
	void Render(float interpolation);

	void Push(GameStatePtr state);
	void Pop();

	bool IsEmpty();

    void LoadWorld(const std::string worldName);
	void LoadEntity(const std::string entityName, sf::Vector2f pos);

private:
	std::stack<GameStatePtr> states;
    WorldFactory* worldFactory;
	EntityFactory* entityFactory;
};

