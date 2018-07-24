#pragma once

#include <LuaBridge.h>
#include <vector>
#include <map>
#include <iostream>
#include "LuaRegistrator.h"

extern "C"{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

using namespace luabridge;

class LuaHandler{
public:
    LuaHandler(std::string _fileName);

    void DoLuaCode(std::string _code);
    LuaRef GetLuaGlobal(const char *_name);
    void RegisterToLua(LuaRegistrator *_registrator);

    template<typename T> void LuaToMap(const LuaRef &_lRef, std::map<std::string, T> &_map)
    {
        _lRef.push(lState);
        push(lState, Nil());
        while (lua_next(lState, -2))
        {
            LuaRef key = LuaRef::fromStack(lState, -2);
            LuaRef val = LuaRef::fromStack(lState, -1);
            _map.insert(std::make_pair(key.cast<std::string>(), val.cast<T>()));
            lua_pop(lState, 1);
        }
    };

    template<typename T> void LuaToVec(const LuaRef &_lRef, std::vector<T> &_vec)
    {
        _lRef.push(lState);
        push(lState, Nil());
        while (lua_next(lState, -2))
        {
            LuaRef val = LuaRef::fromStack(lState, -1);
            _vec.push_back(val.cast<T>());
            lua_pop(lState, 1);
        }
    };

private:
    lua_State* lState;

    void lua_gettostack(const std::string& _variableName);
};


