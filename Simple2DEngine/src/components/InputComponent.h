#pragma once
#include <map>
#include "SFML\Window\Keyboard.hpp"
#include <memory>
#include "core/Command.h"

using KeysMap = std::map<std::string, sf::Keyboard::Key>;
using CommandsMap = std::map<std::string, std::shared_ptr<Command>>;

static KeysMap keysMap
{
	{ "ARROW_UP", sf::Keyboard::Key::Up },
	{ "ARROW_DOWN", sf::Keyboard::Key::Down },
	{ "ARROW_LEFT", sf::Keyboard::Key::Left },
	{ "ARROW_RIGHT", sf::Keyboard::Key::Right },
	{ "SPACE", sf::Keyboard::Key::Space }
};


class InputComponent
{
public:
	InputComponent(CommandsMap commandsMap);
private:
	CommandsMap commandsMap;
};

