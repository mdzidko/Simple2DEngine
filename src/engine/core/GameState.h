#pragma once

#include <memory>
#include <vector>
#include <WorldFactory.h>
#include "Renderer.h"
#include "Updater.h"
#include "World.h"
#include "Context.h"

class GameStateContext;

class GameState
{
public:
	GameState(GameStateContext* context);

    void Update(float updateTime);
	void Render(float interpolation);

    void AddUpdater(UpdaterPtr updater);
    void AddRenderer(RendererPtr renderer);

    void RefreshRenderers();
    void RefreshUpdaters();
    void RegisterEntity(Entity* entity);

	World* getWorld();

private:
    std::vector<RendererPtr> renderers;
    std::vector<UpdaterPtr> updaters;

    WorldPtr world{nullptr};

private:
	GameStateContext* context;
};

typedef std::unique_ptr<GameState> GameStatePtr;