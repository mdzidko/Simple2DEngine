#include <InputComponent.h>
#include "InputUpdater.h"
#include "GameStateContext.h"

void InputUpdater::Update(World *world, GameStateContext *context, float dT)
{
	std::string noKeyPressed("NO_KEY_PRESSED");
	auto key = GetPressedKey();

	for (auto entity : entities)
	{
		auto& ic = entity->GetComponent<InputComponent>();

		if (key == "")
		{
			if(ic.HasCommand(noKeyPressed))
				ic.ExecuteCommand(noKeyPressed);
			else
				return;
		}
		else
			ic.ExecuteCommand(key);
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


