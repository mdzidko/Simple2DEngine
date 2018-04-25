#include <PositionComponent.h>
#include <SpriteComponent.h>
#include <InputComponent.h>
#include <core/TestCommandImpl.h>
#include <MovementComponent.h>
#include "WorldLoaderImpl.h"

WorldPtr WorldLoaderImpl::Load(Context context, GameState* gameState)
{
    WorldPtr newWorld = std::make_unique<World>(context.renderWindow, gameState);
    TexturesHolder* texturesHolder = context.texturesHolder;

    auto rect = std::make_unique<Entity>();

    rect->AddComponent<PositionComponent>(0, 0);
    rect->AddComponent<SpriteComponent>(texturesHolder->Get("GRAVEYARD_BACKGROUND"), RenderLayers::BACK);

	newWorld->AddEntity(std::move(rect));

	rect = std::make_unique<Entity>();

	rect->AddComponent<PositionComponent>(100, 300);
	rect->AddComponent<SpriteComponent>(texturesHolder->Get("PLAYER_IDLE"), RenderLayers::FRONT);

	auto& input = rect->AddComponent<InputComponent>();
	input.AddCommand<TestCommandImpl>("SPACE");

	auto& movement = rect->AddComponent<MovementComponent>();
	movement.SetVelocity({ 1, 0 });

    newWorld->AddEntity(std::move(rect));

    return newWorld;
}
