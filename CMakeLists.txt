cmake_minimum_required(VERSION 3.10)
project(Simple2DEngine)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/utils/commands)
include_directories(src/components)
include_directories(src/ecs)
include_directories(src/engine/core)
include_directories(src/engine/factories)
include_directories(src/systems)

add_executable(Simple2DEngine
        src/utils/commands/Command.h
        src/utils/commands/TestCommandImpl.cpp
        src/utils/commands/TestCommandImpl.h
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
        src/engine/core/Engine.cpp
        src/engine/core/Engine.h
        src/engine/core/GameState.cpp
        src/engine/core/GameState.h
        src/engine/core/GameStateMachine.cpp
        src/engine/core/GameStateMachine.h
        src/engine/core/ResourceHolder.h
        src/engine/core/World.cpp
        src/engine/core/World.h
        src/engine/factories/GSMLoader.h
        src/engine/factories/GSMLoaderImpl.cpp
        src/engine/factories/GSMLoaderImpl.h
        src/engine/factories/MenuStateFactory.cpp
        src/engine/factories/MenuStateFactory.h
        src/engine/factories/PausedStateFactory.cpp
        src/engine/factories/PausedStateFactory.h
        src/engine/factories/PlayingStateFactory.cpp
        src/engine/factories/PlayingStateFactory.h
        src/engine/factories/ResourcesLoader.h
        src/engine/factories/TexturesLoaderImpl.cpp
        src/engine/factories/TexturesLoaderImpl.h
        src/engine/factories/WindowLoader.h
        src/engine/factories/WindowLoaderImpl.cpp
        src/engine/factories/WindowLoaderImpl.h
        src/engine/factories/WorldLoader.h
        src/engine/factories/WorldLoaderImpl.cpp
        src/engine/factories/WorldLoaderImpl.h
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
        src/main.cpp src/systems/AnimationUpdater.cpp src/systems/AnimationUpdater.h src/engine/factories/AnimationsLoaderImpl.cpp src/engine/factories/AnimationsLoaderImpl.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Simple2DEngine ${SFML_LIBRARIES})
endif()
