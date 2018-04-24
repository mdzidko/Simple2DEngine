#include <InputComponent.h>
#include "InputUpdater.h"
#include "core/GameStateMachine.h"
#include <iostream>

void InputUpdater::Update(World *world, GameStateMachine *context, float dT)
{
	auto key = GetPressedKey();

	if (key == "")
		return;

	for (auto entity : entities)
	{
		auto& ic = entity->GetComponent<InputComponent>();
		ic.executeCommand(key);
	}
}
	

bool InputUpdater::CheckEntityMach(Entity *entity)
{
    return entity->HasComponent<InputComponent>();
}

std::string InputUpdater::GetPressedKey()
{
	for (auto& keyPair : keysMap)
		if (sf::Keyboard::isKeyPressed(keyPair.first))
			return keyPair.second;

	return "";
}


