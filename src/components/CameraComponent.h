#pragma once

#include <Component.h>
#include "SFML\System\Vector2.hpp"

class CameraComponent : public Component
{
public:
    CameraComponent(sf::Vector2f offset);

    sf::Vector2f GetOffset();

private:
    sf::Vector2f offset{0, 0};
};
