#pragma once

#include <Component.h>
#include "SFML\System\Vector2.hpp"

class MovementComponent : public Component
{
public:
    const sf::Vector2f &GetVelocity() const;
    void SetVelocity(const sf::Vector2f &velocity);
    const sf::Vector2f &GetAcceleration() const;
    void SetAcceleration(const sf::Vector2f &acceleration);

private:
    sf::Vector2f velocity{0, 0};
    sf::Vector2f acceleration{0, 0};
};
