#pragma once


#include "ResourcesLoader.h"
#include "../../lua/LuaHandler.h"

class LuaTexturesLoader : public TexturesLoader
{
public:
    LuaTexturesLoader(std::string script);

    void Load(TexturesHolder &texturesHolder) override;

private:
    LuaHandler luaHandle;
};

