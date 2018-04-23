#include <InputComponent.h>
#include "InputUpdater.h"
#include "core/GameStateMachine.h"
#include <iostream>

void InputUpdater::Update(World *world, GameStateMachine *context, float dT)
{
	for (auto& keyPair : keysMap)
	{
		if (sf::Keyboard::isKeyPressed(keyPair.first))
		{
			for (auto entity : entities)
			{
				auto ic = entity->GetComponent<InputComponent>();
				auto commandIt = ic.commandsMap.find(keyPair.second);

				auto command = (*commandIt).second;
				command->execute(entity);
			}
		}
	}
	

}

bool InputUpdater::CheckEntityMach(Entity *entity)
{
    return entity->HasComponent<InputComponent>();
}
