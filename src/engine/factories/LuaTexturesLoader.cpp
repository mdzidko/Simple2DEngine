#include "LuaTexturesLoader.h"

LuaTexturesLoader::LuaTexturesLoader(std::string script) : luaHandle(script)
{
}

void LuaTexturesLoader::Load(TexturesHolder &texturesHolder)
{
    try
    {
        std::map<std::string, std::string> texturesMap;
        auto texturesDef = luaHandle.GetLuaGlobal("textures");
        luaHandle.LuaToMap(texturesDef, texturesMap);

        for (auto& td : texturesMap)
        {
            auto textureName = td.first;
            auto textureLocation = td.second;

            texturesHolder.Load(textureName, textureLocation);
        }

    }
    catch (std::exception e)
    {
        std::cout << e.what() << std::endl;
    }
}
