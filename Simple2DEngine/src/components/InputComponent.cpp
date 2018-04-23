#include "InputComponent.h"

InputComponent::InputComponent(CommandsMap commandsMap)
{
	this->commandsMap = std::move(commandsMap);
}