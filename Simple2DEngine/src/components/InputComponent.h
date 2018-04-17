#pragma once
#include <map>
#include "SFML\Window\Keyboard.hpp"
#include <memory>
#include "core/Command.h"

static std::map<std::string, sf::Keyboard::Key> keysMap
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
	InputComponent();
	~InputComponent();

	std::map<std::string, std::shared_ptr<Command>>
};

