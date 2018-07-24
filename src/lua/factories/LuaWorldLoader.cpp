#include <PositionComponent.h>
#include <SpriteComponent.h>
#include <InputComponent.h>
#include <MovementComponent.h>
#include <TestStateCommandImpl.h>
#include <AnimationComponent.h>
#include <StateComponent.h>
#include <CameraComponent.h>
#include "LuaWorldLoader.h"
#include "LuaEntityFactory.h"


WorldPtr LuaWorldLoader::Load(Context context, GameState* gameState)
{
    World* newWorld = new World(context.renderWindow, gameState, {748, 1500});

    entityFactory = std::make_unique<LuaEntityFactory>(newWorld, &context, "resources/scripts/entities.lua");

    entityFactory->Create("player", {180, 300});

    entityFactory->Create("fly", {500, 330});

    entityFactory->Create("background", {0, 0});

    entityFactory->Create("cloud_1", {100, 100});
    entityFactory->Create("cloud_2", {300, 120});
    entityFactory->Create("cloud_3", {600, 50});
    entityFactory->Create("cloud_1", {500, 180});
    entityFactory->Create("cloud_2", {900, 150});
    entityFactory->Create("cloud_1", {1000, 200});
    entityFactory->Create("cloud_3", {1050, 30});

    entityFactory->Create("water_top10", {0, 630});
    entityFactory->Create("water_top10", {700, 630});
    entityFactory->Create("water10", {0, 700});
    entityFactory->Create("water10", {700, 700});

    entityFactory->Create("grass_left", {50, 392});
    entityFactory->Create("grass_mid3", {120, 392});
    entityFactory->Create("grass_right", {330, 392});

    entityFactory->Create("grass_left", {300, 200});
    entityFactory->Create("grass_mid", {370, 200});
    entityFactory->Create("grass_right", {440, 200});
    entityFactory->Create("box", {400, 130});
    entityFactory->Create("plant", {310, 130});

    entityFactory->Create("star", {620, 40});
    entityFactory->Create("bridge3", {400, 342});

    entityFactory->Create("grass_left", {610, 392});
    entityFactory->Create("grass_mid3", {680, 392});
    entityFactory->Create("grass_right", {890, 392});
    entityFactory->Create("fence_broken", {880, 322});
    entityFactory->Create("star", {810, 300});

    entityFactory->Create("sign_right", {60, 322});

    entityFactory->Create("bush", {200, 322});
    entityFactory->Create("bush", {700, 322});
    entityFactory->Create("plant", {780, 322});
    entityFactory->Create("plant", {600, 322});
    entityFactory->Create("mushroom_red", {290, 322});
    entityFactory->Create("plant", {130, 322});

    entityFactory->Create("grass_left", {800, 200});
    entityFactory->Create("grass_mid2", {870, 200});
    entityFactory->Create("grass_right", {1010, 200});
    entityFactory->Create("sign_exit", {1030, 130});
    entityFactory->Create("rock", {820, 130});
    entityFactory->Create("plant", {840, 130});
    entityFactory->Create("mushroom_red", {900, 130});

    return std::unique_ptr<World>(newWorld);
}


