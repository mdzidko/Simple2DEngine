#pragma once

#include <SFML/Graphics/Texture.hpp>
#include "ResourceHolder.h"
#include "../../utils/animation/Animation.h"

template<class T> class ResourcesLoader
{
public:
	virtual void Load(ResourceHolder<T, std::string>& resourcesHolder) = 0;
};

using TexturesLoader = ResourcesLoader<sf::Texture>;
using AnimationsLoader = ResourcesLoader<Animation>;
