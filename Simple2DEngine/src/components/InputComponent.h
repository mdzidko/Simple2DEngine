#pragma once
#include <map>
#include "SFML\Window\Keyboard.hpp"
#include <memory>
#include "core/Command.h"
#include "../ecs/Component.h"

using KeysMap = std::map<sf::Keyboard::Key, std::string>;
using CommandsMap = std::map<std::string, std::unique_ptr<Command>>;

static KeysMap keysMap
{
	{ sf::Keyboard::Key::Up, "ARROW_UP" },
	{ sf::Keyboard::Key::Down, "ARROW_DOWN" },
	{ sf::Keyboard::Key::Left, "ARROW_LEFT" },
	{ sf::Keyboard::Key::Right, "ARROW_RIGHT" },
	{ sf::Keyboard::Key::Space, "SPACE" }
};


class InputComponent : public Component
{
public:
	
	template<class T> void AddCommand(std::string key)
	{
		auto command = std::make_unique<T>();
		commandsMap.insert(std::make_pair(key, std::move(command)));
	}

	void executeCommand(std::string key);

	CommandsMap commandsMap;
};

