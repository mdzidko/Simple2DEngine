#include "LuaFunctionCommand.h"


LuaFunctionCommand::LuaFunctionCommand(std::string functionName, LuaHandler* luaHandle)
{
    this->functionName = functionName;
    this->luaHandle = luaHandle;
}

void LuaFunctionCommand::execute(Entity *entity)
{
    //TODO - add EntityHandle and pass as parameter

    LuaRef fun = luaHandle->GetLuaGlobal(functionName.c_str());
    fun();
}
