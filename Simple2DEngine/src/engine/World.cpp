#include "World.h"
#include "GameState.h"

World::World(sf::RenderWindow* window) : renderWindow(window)
	, worldView(window->getDefaultView())
	, worldBounds(0.f, 0.f, worldView.getSize().x, worldView.getSize().y) 
{

}

void World::AddEntity(EntityPtr entity)
{
	parent->RegisterEntity(entity.get());
	worldEntities.push_back(move(entity));
}

void World::RefreshEntities()
{
	worldEntities.erase(remove_if(worldEntities.begin(), worldEntities.end(),
								  [](const std::unique_ptr<Entity>& uPtr) {return !uPtr->IsAlive(); }), worldEntities.end());
}

sf::RenderWindow* World::GetWorldViewWindow()
{
    renderWindow->setView(worldView);

    return renderWindow;
}

sf::FloatRect& World::GetWorldBounds()
{
    return worldBounds;
}

