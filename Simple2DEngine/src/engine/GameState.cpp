#include "GameState.h"


GameState::GameState(EntitiesVec&& entieties)
{
	stateEntities = std::move(entieties);

	for (const auto& e : stateEntities)
		RegisterEntity(e.get());
}

void GameState::AddContext(GameStateMachine* cont)
{
	context = cont;
}

void GameState::AddEntity(EntityPtr entity)
{
	RegisterEntity(entity.get());
	stateEntities.push_back(std::move(entity));
}

void GameState::RegisterEntity(Entity* entity)
{
	for (const auto& c : renderers)
		c->AddEntity(entity);

	for (const auto& c : updaters)
		c->AddEntity(entity);
}

void GameState::AddUpdater(UpdaterPtr updater)
{
	for (const auto& e : stateEntities)
		updater->AddEntity(e.get());

	updaters.push_back(std::move(updater));
}

void GameState::AddRenderer(RendererPtr renderer)
{
	for (const auto& e : stateEntities)
		renderer->AddEntity(e.get());

	renderers.push_back(std::move(renderer));
}

void GameState::Update(GameStateMachine* context, float updateTime)
{
	Refresh();

	std::for_each(std::begin(updaters), std::end(updaters),
		[&](const auto& updater) { updater->Update(context, updateTime); });
}

void GameState::Render(sf::RenderWindow* window, float interpolation)
{
	Refresh();
	
	std::for_each(std::begin(renderers), std::end(renderers),
		[&](const auto& renderer) { renderer->Update(window, interpolation); });
}

void GameState::Refresh()
{
	RefreshSystems();
	RefreshEntities();
}

void GameState::RefreshEntities()
{
	stateEntities.erase(std::remove_if(stateEntities.begin(), stateEntities.end(),
		[](const std::unique_ptr<Entity>& uPtr) {return !uPtr->IsAlive(); }), stateEntities.end());
}

void GameState::RefreshSystems()
{
	for (const auto& c : renderers) 
		c->Refresh();

	for (const auto& c : updaters)
		c->Refresh();
}


void GameState::ResetEntities(EntitiesVec&& entieties)
{
	stateEntities = std::move(entieties);

	for (const auto& e : stateEntities)
		RegisterEntity(e.get());
}