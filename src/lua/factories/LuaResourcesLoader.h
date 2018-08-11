#pragma once

#include "ResourcesLoader.h"
#include "../core/LuaHandler.h"

template<class ResourceType> class LuaResourcesLoader : public ResourcesLoader<ResourceType>
{
public:
    LuaResourcesLoader(std::string resName, LuaHandler *handle) :
            luaHandle(handle), resourceName(resName)
    {
    }

    void Load(ResourceHolder<ResourceType, std::string>& resourceHolder) override
    {
        try
        {
            std::map<std::string, std::string> resourcesMap;
            auto resourcesDef = luaHandle->GetLuaGlobal(resourceName.c_str());
            luaHandle->LuaToMap(resourcesDef, resourcesMap);

            for (auto& td : resourcesMap)
            {
                auto name = td.first;
                auto location = td.second;

                resourceHolder.Load(name, location);
            }
        }
        catch (std::runtime_error e)
        {
            std::cout << e.what() << std::endl;
        }
    }

private:
    LuaHandler* luaHandle;
    std::string resourceName;
};