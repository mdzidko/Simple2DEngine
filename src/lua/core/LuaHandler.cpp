#include "LuaHandler.h"

LuaHandler::LuaHandler(std::string _fileName)
{
    lState = luaL_newstate();
    luaL_dofile(lState, _fileName.c_str());
    luaL_openlibs(lState);
    lua_pcall(lState, 0, 0, 0);
}

void LuaHandler::lua_gettostack(const std::string& _variableName)
{
    int level = 0;
    std::string var = "";
    for (unsigned int i = 0; i < _variableName.size(); i++)
    {
        if (_variableName.at(i) == '.')
        {
            if (level == 0)
                lua_getglobal(lState, var.c_str());
            else
                lua_getfield(lState, -1, var.c_str());

            if (lua_isnil(lState, -1))
            {
                std::cout << "Error, can't get " << _variableName << std::endl;
                return;
            }
            else
            {
                var = "";
                ++level;
            }
        }
        else
            var += _variableName.at(i);
    }
    if (level == 0)
        lua_getglobal(lState, var.c_str());
    else
        lua_getfield(lState, -1, var.c_str());

    if (level == 0)
        return;

    int tableIndex = lua_gettop(lState) - level;
    lua_replace(lState, tableIndex);
    lua_settop(lState, tableIndex);
}

void LuaHandler::DoLuaCode(std::string _code)
{
    luaL_dostring(lState, _code.c_str());
}

LuaRef LuaHandler::GetLuaGlobal(const char *_name){
    return getGlobal(lState, _name);
}

void LuaHandler::RegisterToLua(LuaRegistrator *_registrator){
    _registrator->RegisterToLua(lState);
}
