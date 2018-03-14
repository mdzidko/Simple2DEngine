#pragma once

#include "Component.h"
#include "SFML\System\Vector2.hpp"

struct PositionComponent : public Component
{
	PositionComponent(sf::Vector2f& pos) : position{ pos } {};

	sf::Vector2f position{ 0, 0 };
};

