cmake_minimum_required(VERSION 3.9)
project(Simple2DEngine)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/utils/commands)
include_directories(src/components)
include_directories(src/ecs)
include_directories(src/engine/core)
include_directories(src/engine/factories)
include_directories(src/systems)
include_directories(D:/Programowanie/LuaBridge)
include_directories(D:/Programowanie/Lua/src)

add_executable(Simple2DEngine
        src/utils/commands/Command.h
        src/utils/commands/TestStateCommandImpl.cpp
        src/utils/commands/TestStateCommandImpl.h
        src/utils/json/json.hpp
        src/components/InputComponent.h
        src/components/MovementComponent.cpp
        src/components/MovementComponent.h
        src/components/PositionComponent.cpp
        src/components/PositionComponent.h
        src/components/SpriteComponent.cpp
        src/components/SpriteComponent.h
        src/ecs/Component.cpp
        src/ecs/Component.h
        src/ecs/Entity.cpp
        src/ecs/Entity.h
        src/ecs/System.h
        src/ecs/UniqueId.h
        src/engine/core/Context.h
        src/engine/core/GameLoop.cpp
        src/engine/core/GameLoop.h
        src/engine/core/GameState.cpp
        src/engine/core/GameState.h
        src/engine/core/GameStateContext.cpp
        src/engine/core/GameStateContext.h
        src/engine/core/ResourceHolder.h
        src/engine/core/World.cpp
        src/engine/core/World.h
        src/lua/factories/MenuStateFactory.cpp
        src/lua/factories/MenuStateFactory.h
        src/lua/factories/PlayingStateFactory.cpp
        src/lua/factories/PlayingStateFactory.h
        src/engine/factories/ResourcesLoader.h
        src/engine/factories/WindowLoader.h
        src/lua/factories/WindowLoaderImpl.cpp
        src/lua/factories/WindowLoaderImpl.h
        src/engine/factories/WorldFactory.h
        src/lua/factories/LuaWorldFactory.cpp
        src/lua/factories/LuaWorldFactory.h
        src/systems/InputUpdater.cpp
        src/systems/InputUpdater.h
        src/systems/MovementUpdater.cpp
        src/systems/MovementUpdater.h
        src/systems/Renderer.h
        src/systems/SpritesRenderer.cpp
        src/systems/SpritesRenderer.h
        src/systems/Updater.cpp
        src/systems/Updater.h
        src/components/StateComponent.h
        src/components/CommandComponent.cpp
        src/components/CommandComponent.h
        src/components/CameraComponent.cpp
        src/components/CameraComponent.h
        src/components/StateComponent.cpp
        src/systems/StateUpdater.cpp
        src/systems/StateUpdater.h
        src/components/AnimationComponent.cpp
        src/components/AnimationComponent.h
        src/systems/AnimationRenderer.cpp
        src/systems/AnimationRenderer.h
        src/utils/animation/Animation.cpp
        src/utils/animation/Animation.h
        src/utils/animation/AnimatedSprite.cpp
        src/utils/animation/AnimatedSprite.h
        src/main.cpp
        src/systems/AnimationUpdater.cpp
        src/systems/AnimationUpdater.h
        src/systems/CameraUpdater.cpp
        src/systems/CameraUpdater.h
        src/lua/factories/LuaResourcesLoader.h
        src/lua/core/LuaHandler.cpp
        src/lua/core/LuaHandler.h
        src/engine/factories/EntityFactory.h
        src/lua/core/LuaRegistrator.h
        src/lua/factories/LuaEntityFactory.cpp
        src/lua/factories/LuaEntityFactory.h src/lua/factories/LuaFunctionCommand.cpp src/lua/factories/LuaFunctionCommand.h src/utils/collisions/Body.h src/utils/collisions/QuadTree.cpp src/utils/collisions/QuadTree.h src/components/CollisionComponent.cpp src/components/CollisionComponent.h src/systems/CollisionSystem.cpp src/systems/CollisionSystem.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Simple2DEngine ${SFML_LIBRARIES})
endif()

target_link_libraries(Simple2DEngine D:/Programowanie/Lua/lib/liblua.a)
