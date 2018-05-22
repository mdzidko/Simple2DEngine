#pragma once
#include "Component.h"
#include "SFML\Graphics\Texture.hpp"
#include "SFML\Graphics\Sprite.hpp"

struct SpriteComponent : public Component
{
public:
	SpriteComponent(const sf::Texture& texture, RenderLayers layer, int sizeX = 0, int sizeY = 0, bool isRepeated = false );

	sf::Sprite sprite;
	RenderLayers renderLayer;
	sf::IntRect rect;
	bool repeated;
};

