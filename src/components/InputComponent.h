#pragma once

#include "SFML\Window\Keyboard.hpp"
#include "CommandComponent.h"


using KeysMap = std::map<sf::Keyboard::Key, std::string>;

static KeysMap keysMap
{
	{ sf::Keyboard::Key::Up, "ARROW_UP" },
	{ sf::Keyboard::Key::Down, "ARROW_DOWN" },
	{ sf::Keyboard::Key::Left, "ARROW_LEFT" },
	{ sf::Keyboard::Key::Right, "ARROW_RIGHT" },
	{ sf::Keyboard::Key::Space, "SPACE" }
};


class InputComponent : public CommandComponent
{
};

