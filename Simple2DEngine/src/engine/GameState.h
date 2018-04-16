#pragma once

#include <memory>
#include <vector>
#include "Renderer.h"
#include "Updater.h"
#include "World.h"

class GameStateMachine;

class GameState
{
public:
    void Update(GameStateMachine* gsm, float updateTime);
	void Render(float interpolation);

    void AddUpdater(UpdaterPtr updater);
    void AddRenderer(RendererPtr renderer);

    void RefreshRenderers();
    void RefreshUpdaters();
    void RegisterEntity(Entity* entity);

private:
    std::vector<RendererPtr> renderers;
    std::vector<UpdaterPtr> updaters;

    std::unique_ptr<World> world{nullptr};
};

typedef std::unique_ptr<GameState> GameStatePtr;