#pragma once

#include <memory>
#include <vector>
#include "Entity.h"
#include "SFML/Graphics/RenderWindow.hpp"

using EntityPtr =std::unique_ptr<Entity>;
using EntitiesVec = std::vector<EntityPtr>;

class GameState;

class World
{
public:
	World(sf::RenderWindow* window, GameState* gameState, sf::Vector2f worldSize);

	void AddEntity(EntityPtr entity);
	void RefreshEntities();

    sf::RenderWindow* GetWorldViewWindow();
    sf::FloatRect& GetWorldBounds();
    sf::View worldView;

private:
    GameState* parent;
    EntitiesVec worldEntities;
    sf::FloatRect worldBounds;
    sf::RenderWindow* renderWindow;
	//QuadTree quadTree
};

using WorldPtr = std::unique_ptr<World>;