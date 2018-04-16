#include <iostream>
#include <TexturesLoaderImpl.h>
#include <GSMLoaderImpl.h>
#include "Engine.h"
#include "WindowLoaderImpl.h"


int main()
{
	//Entity creation
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


	TexturesLoaderImpl txLoader;
	WindowLoaderImpl winLoader;
    GSMLoaderImpl gsLoader;

	Engine engine;//std::move(window), std::move(stateMachine));

	//Run
	engine.Init(&winLoader, &gsLoader, &txLoader);
	engine.Run();

	system("PAUSE");
}