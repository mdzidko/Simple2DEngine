//
// Created by Michał on 2018-04-13.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include "WindowLoaderImpl.h"

WindowPtr WindowLoaderImpl::Load()
{
    auto window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1024, 768), "Main window");

    return window;
}
