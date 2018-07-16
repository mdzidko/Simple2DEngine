#pragma once

#include <LuaBridge.h>

using namespace luabridge;

class LuaRegistrator
{
public:
    virtual void RegisterToLua(lua_State *_lState) = 0;
};
