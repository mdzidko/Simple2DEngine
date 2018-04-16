#pragma once

#include "Renderer.h"
#include "SFML\Graphics\RenderWindow.hpp"
#include "SpriteComponent.h"
#include <map>

using LayeredEntitiesMap = std::map<RenderLayers, std::vector<Entity*>>;

class RenderingSystem : public Renderer
{
public:
	virtual void Render(sf::RenderWindow* window, float interpolation) override;
	virtual void Refresh() override;

protected:	
	LayeredEntitiesMap entitiesMap;

	virtual bool CheckEntityMach(Entity* entity) override;
	virtual void AddEntityToContainer(Entity* entity) override;
};

