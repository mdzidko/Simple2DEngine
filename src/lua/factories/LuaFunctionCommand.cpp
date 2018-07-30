#include "LuaFunctionCommand.h"


LuaFunctionCommand::LuaFunctionCommand(std::string functionName, std::string script) :
    luaHandle(script)
{
    this->functionName = functionName;
}

void LuaFunctionCommand::execute(Entity *entity)
{
    //TODO - add EntityHandle and pass as parameter

    LuaRef fun = luaHandle.GetLuaGlobal(functionName.c_str());
    fun();
}
