#include <PositionComponent.h>
#include <SpriteComponent.h>
#include <InputComponent.h>
#include <MovementComponent.h>
#include <TestStateCommandImpl.h>
#include <AnimationComponent.h>
#include <StateComponent.h>
#include <CameraComponent.h>
#include "WorldLoaderImpl.h"

WorldPtr WorldLoaderImpl::Load(Context context, GameState* gameState)
{
    World* newWorld = new World(context.renderWindow, gameState, {748, 1500});

    LoadPlayer(newWorld, {180, 300}, context);

    LoadEnemy(newWorld, {500, 330}, context);

    LoadMapElement(newWorld, "BACKGROUND", {0, 0}, {1500, 768}, true, context);

    LoadMapElement(newWorld, "CLOUD_1", {100, 100}, {128, 71}, false, context);
    LoadMapElement(newWorld, "CLOUD_2", {300, 120}, {129, 71}, false, context);
    LoadMapElement(newWorld, "CLOUD_3", {600, 50}, {129, 71}, false, context);
    LoadMapElement(newWorld, "CLOUD_1", {500, 180}, {128, 71}, false, context);
    LoadMapElement(newWorld, "CLOUD_2", {900, 150}, {129, 71}, false, context);
    LoadMapElement(newWorld, "CLOUD_1", {1000, 200}, {128, 71}, false, context);
    LoadMapElement(newWorld, "CLOUD_3", {1050, 30}, {129, 71}, false, context);

    LoadMapElement(newWorld, "WATER_TOP", {0, 630}, {1500, 70}, true, context);
    LoadMapElement(newWorld, "WATER", {0, 700}, {1500, 70}, true, context);

    LoadMapElement(newWorld, "GRASS_LEFT", {50, 392}, {70, 70}, false, context);
    LoadMapElement(newWorld, "GRASS_MID", {120, 392}, {210, 70}, true, context);
    LoadMapElement(newWorld, "GRASS_RIGHT", {330, 392}, {70, 70}, false, context);

    LoadMapElement(newWorld, "GRASS_LEFT", {300, 200}, {70, 70}, false, context);
    LoadMapElement(newWorld, "GRASS_MID", {370, 200}, {70, 70}, true, context);
    LoadMapElement(newWorld, "GRASS_RIGHT", {440, 200}, {70, 70}, false, context);
    LoadMapElement(newWorld, "BOX", {400, 130}, {70, 70}, false, context);
    LoadMapElement(newWorld, "PLANT", {310, 130}, {70, 70}, false, context);

    LoadMapElement(newWorld, "STAR", {620, 40}, {70, 70}, false, context);
    LoadMapElement(newWorld, "BRIDGE", {400, 342}, {210, 70}, true, context);

    LoadMapElement(newWorld, "GRASS_LEFT", {610, 392}, {70, 70}, false, context);
    LoadMapElement(newWorld, "GRASS_MID", {680, 392}, {210, 70}, true, context);
    LoadMapElement(newWorld, "GRASS_RIGHT", {890, 392}, {70, 70}, false, context);
    LoadMapElement(newWorld, "FENCE_BROKEN", {880, 322}, {70, 70}, false, context);
    LoadMapElement(newWorld, "STAR", {810, 300}, {70, 70}, false, context);

    LoadMapElement(newWorld, "SIGN_RIGHT", {60, 322}, {70, 70}, false, context);

    LoadMapElement(newWorld, "BUSH", {200, 322}, {70, 70}, false, context);
    LoadMapElement(newWorld, "BUSH", {700, 322}, {70, 70}, false, context);
    LoadMapElement(newWorld, "PLANT", {780, 322}, {70, 70}, false, context);
    LoadMapElement(newWorld, "PLANT", {600, 322}, {70, 70}, false, context);
    LoadMapElement(newWorld, "MUSHROOM_RED", {290, 322}, {70, 70}, false, context);
    LoadMapElement(newWorld, "PLANT", {130, 322}, {70, 70}, false, context);

    LoadMapElement(newWorld, "GRASS_LEFT", {800, 200}, {70, 70}, false, context);
    LoadMapElement(newWorld, "GRASS_MID", {870, 200}, {140, 70}, true, context);
    LoadMapElement(newWorld, "GRASS_RIGHT", {1010, 200}, {70, 70}, false, context);
    LoadMapElement(newWorld, "SIGN_EXIT", {1030, 130}, {70, 70}, false, context);
    LoadMapElement(newWorld, "ROCK", {820, 130}, {70, 70}, false, context);
    LoadMapElement(newWorld, "PLANT", {840, 130}, {70, 70}, false, context);
    LoadMapElement(newWorld, "MUSHROOM_RED", {900, 130}, {70, 70}, false, context);


    return std::unique_ptr<World>(newWorld);
}

void WorldLoaderImpl::LoadPlayer(World* world, sf::Vector2f pos, Context &context)
{
    TexturesHolder* texturesHolder = context.texturesHolder;
    AnimationsHolder* animationsHolder = context.animationsHolder;

    auto ent = std::make_unique<Entity>();

    ent = std::make_unique<Entity>();

    ent->AddComponent<PositionComponent>(pos);

    auto& animComp = ent->AddComponent<AnimationComponent>(10.f, RenderLayers::FRONT);
    animComp.AddAnimation("PLAYER_WALK", &animationsHolder->Get("PLAYER_WALK"));
    animComp.AddAnimation("PLAYER_IDDLE", &animationsHolder->Get("PLAYER_IDDLE"));

    auto& input = ent->AddComponent<InputComponent>();
    input.AddCommand<RightKeyPressedCommand>("ARROW_RIGHT");
    input.AddCommand<LeftKeyPressedCommand>("ARROW_LEFT");
    input.AddCommand<NoKeyPressedCommand>("NO_KEY_PRESSED");

    auto& state = ent->AddComponent<StateComponent>();
    state.AddCommand<TestStateCommandImpl>("IDDLE");
    state.AddCommand<TestStateCommandImpl>("MOVE_RIGHT");
    state.AddCommand<TestStateCommandImpl>("MOVE_LEFT");

    auto& movement = ent->AddComponent<MovementComponent>();
    auto& camera = ent->AddComponent<CameraComponent>(sf::Vector2f(350, 100));

    world->AddEntity(std::move(ent));
}

void WorldLoaderImpl::LoadMapElement(World* world, std::string textureName, sf::Vector2f pos, sf::Vector2f size, bool repeated, Context &context)
{
    TexturesHolder* texturesHolder = context.texturesHolder;
    AnimationsHolder* animationsHolder = context.animationsHolder;
    auto rect = std::make_unique<Entity>();

    rect->AddComponent<PositionComponent>(pos);
    rect->AddComponent<SpriteComponent>(texturesHolder->Get(textureName), RenderLayers::BACK, size.x, size.y, repeated);

    world->AddEntity(std::move(rect));
}

void WorldLoaderImpl::LoadEnemy(World* world, sf::Vector2f pos, Context &context)
{
    TexturesHolder* texturesHolder = context.texturesHolder;
    AnimationsHolder* animationsHolder = context.animationsHolder;

    auto ent = std::make_unique<Entity>();

    ent = std::make_unique<Entity>();

    ent->AddComponent<PositionComponent>(pos);

    auto& animComp = ent->AddComponent<AnimationComponent>(300.f, RenderLayers::FRONT);
    animComp.AddAnimation("FLY", &animationsHolder->Get("FLY"));
    animComp.PlayAnimation("FLY", false);

    world->AddEntity(std::move(ent));
}
