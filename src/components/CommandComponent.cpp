#include "CommandComponent.h"

void CommandComponent::ExecuteCommand(std::string key)
{
    auto commandIt = commandsMap.find(key);

    if (commandIt != commandsMap.end())
    {
        auto command = commandIt->second.get();
        command->execute(parent);
    }
}