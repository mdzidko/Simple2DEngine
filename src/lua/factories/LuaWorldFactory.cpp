#include <PositionComponent.h>
#include <SpriteComponent.h>
#include <InputComponent.h>
#include "LuaWorldFactory.h"
#include "LuaEntityFactory.h"


LuaWorldFactory::LuaWorldFactory(LuaHandler* luaHandle, sf::RenderWindow* renderWindow)
{
    this->luaHandle = luaHandle;
    this->renderWindow = renderWindow;
}

WorldPtr LuaWorldFactory::Load(const std::string& worldName, GameState* gameState, EntityFactory* entityFactory)
{
    World* newWorld = new World(renderWindow, gameState, {748, 1500});

    std::vector<LuaRef> entitiesDefVec;

    auto worldDef = luaHandle->GetLuaGlobal(worldName.c_str());
    luaHandle->LuaToVec(worldDef, entitiesDefVec);

    for(auto entityDef : entitiesDefVec)
    {
        std::vector<std::string> entityParams;
        luaHandle->LuaToVec(entityDef, entityParams);

        auto name = entityParams[0];
        auto x = std::stoi(entityParams[1]);
        auto y = std::stoi(entityParams[2]);

        entityFactory->Create(newWorld, name, {x, y});
    }

    return std::unique_ptr<World>(newWorld);
}




