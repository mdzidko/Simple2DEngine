#include <PositionComponent.h>
#include <SpriteComponent.h>
#include <InputComponent.h>
#include "LuaWorldLoader.h"
#include "LuaEntityFactory.h"


LuaWorldLoader::LuaWorldLoader(std::string script) : luaHandle(script)
{
}

WorldPtr LuaWorldLoader::Load(Context context, GameState* gameState)
{
    World* newWorld = new World(context.renderWindow, gameState, {748, 1500});

    entityFactory = std::make_unique<LuaEntityFactory>(newWorld, &context, "resources/scripts/entities.lua");

    std::vector<LuaRef> entitiesDefVec;

    auto worldDef = luaHandle.GetLuaGlobal("base_world");
    luaHandle.LuaToVec(worldDef, entitiesDefVec);

    for(auto entityDef : entitiesDefVec)
    {
        std::vector<std::string> entityParams;
        luaHandle.LuaToVec(entityDef, entityParams);

        auto name = entityParams[0];
        auto x = std::stoi(entityParams[1]);
        auto y = std::stoi(entityParams[2]);

        entityFactory->Create(name, {x, y});
    }

    return std::unique_ptr<World>(newWorld);
}




