#include "LuaEntityFactory.h"
#include "LuaFunctionCommand.h"

LuaEntityFactory::LuaEntityFactory(TexturesHolder* texturesHolder, AnimationsHolder* animationsHolder, LuaHandler* luaHandle)
{
    this->texturesHolder = texturesHolder;
    this->animationsHolder = animationsHolder;
    this->luaHandle = luaHandle;
};

void LuaEntityFactory::Create(World* world, std::string _objectName, sf::Vector2f pos){
    auto e = std::make_unique<Entity>();

    std::cout << "Creating game entity: " << _objectName << std::endl;

    std::map<std::string, LuaRef> componentsMap;

    auto entitiesDef = luaHandle->GetLuaGlobal(_objectName.c_str());
    luaHandle->LuaToMap(entitiesDef, componentsMap);

    for (auto& c : componentsMap) {
        auto componentName = c.first;
        auto value = c.second;
        if (componentName == "PositionComponent") {
            AddPositionComponent(e.get(), pos);
        }
        else if (componentName == "SpriteComponent") {
            AddSpriteComponent(e.get(), value);
        }
        else if (componentName == "AnimationComponent") {
            AddAnimationComponent(e.get(), value);
        }
        else if (componentName == "InputComponent") {
            AddInputComponent(e.get(), value);
        }
        else if (componentName == "StateComponent") {
            AddStateComponent(e.get(), value);
        }
        else if (componentName == "MovementComponent") {
            AddMovementComponent(e.get(), value);
        }
        else if (componentName == "CameraComponent") {
            AddCameraComponent(e.get(), value);
        }

        std::cout << "--Added component " << componentName << std::endl;
    }

    world->AddEntity(std::move(e));

    //EntityHandler* hPtr = new EntityHandler(e);
    //hManager->push_back(hPtr);

    std::cout << "--------------------------------------------------------------" << std::endl;

    //EntityHandler* hPtr = new EntityHandler(e);

    //return hPtr;
}

void LuaEntityFactory::AddPositionComponent(Entity *entity, sf::Vector2f pos)
{
    entity->AddComponent<PositionComponent>(pos);
}

void LuaEntityFactory::AddSpriteComponent(Entity *entity, LuaRef value)
{
    auto sizex = value["size_x"];
    auto sizey = value["size_y"];
    auto textureName = value["texture"];
    auto repeated = value["repeated"];
    auto layerName = value["layer"];

    entity->AddComponent<SpriteComponent>(texturesHolder->Get(textureName), GetRenderLayer(layerName), sizex.cast<int>(), sizey.cast<int>(), repeated);
}

void LuaEntityFactory::AddAnimationComponent(Entity *entity, LuaRef value)
{
    auto layerName = value["layer"];
    auto activeAnimation = value["activeAnimation"];

    std::vector<std::string> animationsVec;

    auto animations = value["animations"];
    luaHandle->LuaToVec(animations, animationsVec);

    auto& animComp = entity->AddComponent<AnimationComponent>(300.f, GetRenderLayer(layerName));

    for(auto animationName : animationsVec)
        animComp.AddAnimation(animationName, &animationsHolder->Get(animationName));

    animComp.PlayAnimation(activeAnimation, false);
}


RenderLayers LuaEntityFactory::GetRenderLayer(std::string layerName)
{
    auto layerIt = renderLayersMap.find(layerName);
    return layerIt->second;
}

void LuaEntityFactory::AddInputComponent(Entity *pEntity, LuaRef lua)
{
    auto& input = pEntity->AddComponent<InputComponent>();

    std::map<std::string, std::string> inputs;
    luaHandle->LuaToMap(lua, inputs);

    for(auto& inputDef : inputs)
        input.AddCommand<LuaFunctionCommand>(inputDef.first, inputDef.second, luaHandle);
}

void LuaEntityFactory::AddStateComponent(Entity *pEntity, LuaRef lua)
{
    auto& state = pEntity->AddComponent<StateComponent>();

    std::map<std::string, std::string> states;
    luaHandle->LuaToMap(lua, states);

    for(auto& stateDef : states)
        state.AddCommand<LuaFunctionCommand>(stateDef.first, stateDef.second, luaHandle);
}

void LuaEntityFactory::AddMovementComponent(Entity *pEntity, LuaRef lua)
{
    auto& movement = pEntity->AddComponent<MovementComponent>();
}

void LuaEntityFactory::AddCameraComponent(Entity *pEntity, LuaRef lua)
{
    auto& camera = pEntity->AddComponent<CameraComponent>(sf::Vector2f(350, 100));
}
