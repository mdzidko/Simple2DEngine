#pragma once

#include "System.h"
#include "SFML\Graphics\RenderWindow.hpp"
#include "SpriteComponent.h"
#include <map>

using LayeredEntitiesMap = std::map<RenderLayers, std::vector<Entity*>>;

class Renderer : public System
{
public:
	virtual void Render(sf::RenderWindow* window, float interpolation) = 0;

protected:
	LayeredEntitiesMap entitiesMap;
};

using RendererPtr = std::unique_ptr<Renderer>;

