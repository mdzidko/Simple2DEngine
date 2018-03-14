#pragma once
#include "Component.h"
#include "SFML\Graphics\Texture.hpp"
#include "SFML\Graphics\Sprite.hpp"

enum class RenderLayers
{
	BACK = 1,
	MIDDLE = 2,
	FRONT = 3
};

struct SpriteComponent : public Component
{
public:
	SpriteComponent(const sf::Texture& texture, RenderLayers layer, bool isRepeated = false);

	sf::Sprite sprite;
	RenderLayers renderLayer;
	bool repeated;
};

