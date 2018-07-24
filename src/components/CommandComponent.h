#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <Command.h>
#include <Component.h>

using CommandsMap = std::map<std::string, std::unique_ptr<Command>>;

class CommandComponent : public Component
{
public:
    template<class T, typename... TArgs> void AddCommand(std::string key, TArgs... args)
    {
        auto command = std::make_unique<T>((args)...);
        commandsMap.insert(std::make_pair(key, std::move(command)));
    }

    void ExecuteCommand(std::string key);
    bool HasCommand(std::string key);

protected:
    CommandsMap commandsMap;
};



