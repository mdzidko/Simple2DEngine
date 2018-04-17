#pragma once

#include <core/ResourceHolder.h>
#include <SFML/Graphics/RenderWindow.hpp>

struct Context
{
    sf::RenderWindow* renderWindow;
    TexturesHolder* texturesHolder;
};
