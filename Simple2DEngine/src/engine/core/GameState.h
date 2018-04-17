#pragma once

#include <memory>
#include <vector>
#include <factories/WorldLoader.h>
#include <core/Context.h>
#include "Renderer.h"
#include "Updater.h"
#include "World.h"

class GameStateMachine;

class GameState
{
public:
	GameState(Context context);

    void Update(GameStateMachine* gsm, float updateTime);
	void Render(float interpolation);

    void AddUpdater(UpdaterPtr updater);
    void AddRenderer(RendererPtr renderer);

    void RefreshRenderers();
    void RefreshUpdaters();
    void RegisterEntity(Entity* entity);

    void LoadWorld(WorldLoader* worldLoader);

private:
    std::vector<RendererPtr> renderers;
    std::vector<UpdaterPtr> updaters;

    WorldPtr world{nullptr};
	Context gameContext;
};

typedef std::unique_ptr<GameState> GameStatePtr;