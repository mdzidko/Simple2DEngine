#pragma once

#include <string>
#include <Command.h>

class LuaFunctionCommand : public Command
{
public:
    LuaFunctionCommand(std::string functionName);

    void execute(Entity *entity) override;

private:
    std::string functionName;
};

