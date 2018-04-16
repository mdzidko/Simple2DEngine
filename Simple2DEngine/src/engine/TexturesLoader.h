#pragma once

#include <SFML\Graphics\Texture.hpp>
#include "ResourceHolder.h"

class TexturesLoader
{
public:
	virtual void Load(ResourceHolder<sf::Texture, std::string>& texturesHolder) = 0;
};

