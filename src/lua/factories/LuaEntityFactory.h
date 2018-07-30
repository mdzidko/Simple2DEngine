#pragma once

#include <iostream>
#include <EntityFactory.h>
#include <Context.h>
#include "PositionComponent.h"
#include "SpriteComponent.h"
#include "MovementComponent.h"
#include "InputComponent.h"
#include "StateComponent.h"
#include "AnimationComponent.h"
#include "CameraComponent.h"
#include "../core/LuaHandler.h"

using namespace luabridge;

//using handlersManager = std::vector<EntityHandler*>;



class LuaEntityFactory : public EntityFactory{
public:
    LuaEntityFactory(World* _world, Context* _context, std::string luaScript);

    void Create(std::string _objectName, sf::Vector2f pos);

private:
    void AddPositionComponent(Entity *entity, sf::Vector2f pos);
    void AddSpriteComponent(Entity *entity, LuaRef value);
    void AddAnimationComponent(Entity *entity, LuaRef value);
    void AddInputComponent(Entity *pEntity, LuaRef lua);
    void AddStateComponent(Entity *pEntity, LuaRef lua);
    void AddMovementComponent(Entity *pEntity, LuaRef lua);
    void AddCameraComponent(Entity *pEntity, LuaRef lua);

    RenderLayers GetRenderLayer(std::string);

    //handlersManager* hManager = nullptr;
    LuaHandler luaHandle;
    std::string script;

    std::map<std::string, RenderLayers> renderLayersMap{
            {"BACK", RenderLayers::BACK},
            {"FRONT", RenderLayers::FRONT},
            {"MIDDLE", RenderLayers::BACK}
    };


};