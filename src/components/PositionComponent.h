#pragma once

#include "Component.h"
#include "SFML\System\Vector2.hpp"

struct PositionComponent : public Component
{
public:
    PositionComponent();
	PositionComponent(sf::Vector2f& pos);
    PositionComponent(float x, float y);

	const sf::Vector2f& GetPosition() const;
	void SetPosition(const sf::Vector2f& position);

private:
	sf::Vector2f position{ 0, 0 };
};

