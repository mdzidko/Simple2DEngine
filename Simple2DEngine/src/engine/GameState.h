#pragma once

#include <memory>
#include <vector>
#include "RenderingSystem.h"
#include "SimpleUpdater.h"

class SimpleUpdater;

using RendererPtr = std::unique_ptr<RenderingSystem>;
using UpdaterPtr = std::unique_ptr<SimpleUpdater>;
using EntityPtr = std::unique_ptr<Entity>;
using EntitiesVec = std::vector<EntityPtr>;

class GameStateMachine;

class GameState {
public:	
	GameState(EntitiesVec&& entieties);

	void AddContext(GameStateMachine* context);

	void AddEntity(EntityPtr entity);
	void ResetEntities(EntitiesVec&& entieties);

	void AddRenderer(RendererPtr renderer);
	void AddUpdater(UpdaterPtr updater);

	void Update(GameStateMachine* context, float updateTime);
	void Render(sf::RenderWindow* window, float interpolation);

protected:
	GameStateMachine* context;
	
	EntitiesVec stateEntities;

	std::vector<RendererPtr> renderers;
	std::vector<UpdaterPtr> updaters;

	void Refresh();
	void RefreshEntities();
	void RefreshSystems();
	void RegisterEntity(Entity* entity);
};

typedef std::unique_ptr<GameState> GameStatePtr;