#include <PositionComponent.h>
#include <SpriteComponent.h>
#include <InputComponent.h>
#include <MovementComponent.h>
#include <TestCommandImpl.h>
#include <AnimationComponent.h>
#include "WorldLoaderImpl.h"

WorldPtr WorldLoaderImpl::Load(Context context, GameState* gameState)
{
    WorldPtr newWorld = std::make_unique<World>(context.renderWindow, gameState);
    TexturesHolder* texturesHolder = context.texturesHolder;
    AnimationsHolder* animationsHolder = context.animationsHolder;

    auto rect = std::make_unique<Entity>();

    rect->AddComponent<PositionComponent>(0, 0);
    rect->AddComponent<SpriteComponent>(texturesHolder->Get("BACKGROUND"), RenderLayers::BACK, 1024, 768, true);

	newWorld->AddEntity(std::move(rect));

	rect = std::make_unique<Entity>();

	rect->AddComponent<PositionComponent>(100, 300);
	//rect->AddComponent<SpriteComponent>(texturesHolder->Get("PLAYER"), RenderLayers::FRONT);
    auto& animComp = rect->AddComponent<AnimationComponent>(0.1f, RenderLayers::FRONT);
    animComp.AddAnimation("PLAYER_WALK", &animationsHolder->Get("PLAYER_WALK"));
    animComp.PlayAnimation("PLAYER_WALK");

	auto& input = rect->AddComponent<InputComponent>();
	input.AddCommand<TestCommandImpl>("SPACE");

	auto& movement = rect->AddComponent<MovementComponent>();

    newWorld->AddEntity(std::move(rect));

    return newWorld;
}
