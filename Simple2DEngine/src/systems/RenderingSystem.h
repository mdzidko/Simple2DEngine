#pragma once

#include "System.h"
#include "SFML\Graphics\RenderWindow.hpp"
#include "SpriteComponent.h"
#include <map>

using LayeredEntitiesMap = std::map<RenderLayers, std::vector<Entity*>>;

class RenderingSystem : public System
{
public:
	virtual void Update(sf::RenderWindow* window, float interpolation);
	virtual void Refresh() override;

protected:	
	LayeredEntitiesMap entitiesMap;

	virtual bool CheckEntityMach(Entity* entity) override;
	virtual void AddEntityToContainer(Entity* entity) override;
};

