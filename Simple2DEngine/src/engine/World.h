#pragma once

#include <memory>
#include <vector>
#include "Entity.h"
#include "SFML\Graphics\RenderWindow.hpp"

using EntityPtr =std::unique_ptr<Entity>;
using EntitiesVec = std::vector<EntityPtr>;

class GameState;

class World
{
public:
	World(sf::RenderWindow* window);

	void AddEntity(EntityPtr entity);
	void RefreshEntities();

    sf::RenderWindow* GetWorldViewWindow();
    sf::FloatRect& GetWorldBounds();

private:
    GameState* parent;
    EntitiesVec worldEntities;
	sf::View worldView;
    sf::FloatRect worldBounds;
    sf::RenderWindow* renderWindow;
};