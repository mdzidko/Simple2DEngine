#include <algorithm>
#include "GameState.h"

GameState::GameState(GameStateContext* context)
{
    this->context = context;
}

void GameState::Update(float updateTime)
{
    RefreshUpdaters();

	if(world == nullptr)
		return;

    std::for_each(std::begin(updaters), std::end(updaters),
                  [&](const auto& updater) { updater->Update(world.get(), context, updateTime); });
}

void GameState::Render(float interpolation)
{
    RefreshRenderers();

	if(world == nullptr)
		return;

    auto renderWindow = world->GetWorldViewWindow();

    std::for_each(std::begin(renderers), std::end(renderers),
                  [&](const auto& renderer) { renderer->Render(renderWindow, interpolation); });
}

void GameState::RefreshRenderers()
{
	for (const auto& r : renderers)
		r->Refresh();
}

void GameState::RefreshUpdaters()
{
    for (const auto& u : updaters)
		u->Refresh();
}

void GameState::RegisterEntity(Entity* entity)
{
	for (const auto& r : renderers)
		r->AddEntity(entity);

	for (const auto& u : updaters)
		u->AddEntity(entity);
}

void GameState::AddUpdater(UpdaterPtr updater)
{
	updaters.push_back(move(updater));
}

void GameState::AddRenderer(RendererPtr renderer)
{
	renderers.push_back(move(renderer));
}

World* GameState::getWorld()
{
	return world.get();
}
