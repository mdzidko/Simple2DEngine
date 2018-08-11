#pragma once

#include <string>
#include <Command.h>
#include "../core/LuaHandler.h"

class LuaFunctionCommand : public Command
{
public:
    LuaFunctionCommand(std::string functionName, LuaHandler* luaHandle);

    void execute(Entity *entity) override;

private:
    std::string functionName;
    LuaHandler* luaHandle;
};

