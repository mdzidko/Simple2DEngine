#include <PositionComponent.h>
#include <SpriteComponent.h>
#include <InputComponent.h>
#include <core/TestCommandImpl.h>
#include "WorldLoaderImpl.h"

WorldPtr WorldLoaderImpl::Load(Context context, GameState* gameState)
{
    WorldPtr newWorld = std::make_unique<World>(context.renderWindow, gameState);
    TexturesHolder* texturesHolder = context.texturesHolder;

    auto rect = std::make_unique<Entity>();

    auto initPos = sf::Vector2f(0, 0);
    rect->AddComponent<PositionComponent>(initPos);
    rect->AddComponent<SpriteComponent>(texturesHolder->Get("GRAVEYARD_BACKGROUND"), RenderLayers::BACK);


	auto& input = rect->AddComponent<InputComponent>();
	input.AddCommand<TestCommandImpl>("SPACE");

    newWorld->AddEntity(std::move(rect));

    return newWorld;
}


/*auto rect = std::make_unique<Entity>();

auto initPos = sf::Vector2f(0, 0);
rect->AddComponent<PositionComponent>(initPos);
rect->AddComponent<SpriteComponent>(texturesHolder.Get("GRAVEYARD_BACKGROUND"), RenderLayers::BACK);

EntitiesVec objVec;
objVec.push_back(std::move(rect));

rect = std::make_unique<Entity>();

initPos = sf::Vector2f(60, 500);
rect->AddComponent<PositionComponent>(initPos);
rect->AddComponent<SpriteComponent>(texturesHolder.Get("TILE01"), RenderLayers::MIDDLE);
objVec.push_back(std::move(rect));

auto player = std::make_unique<Entity>();

initPos = sf::Vector2f(200, 500);
player->AddComponent<PositionComponent>(initPos);
player->AddComponent<SpriteComponent>(texturesHolder.Get("PLAYER_IDLE"), RenderLayers::FRONT);
objVec.push_back(std::move(player));*/
