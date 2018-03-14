#include <iostream>
#include "SFMLWindowFactory.h"
#include "SimpleUpdater.h"
#include "GameStateMachine.h"
#include "Engine.h"
#include "PositionComponent.h"
#include "ResourceHolder.h"
#include "SFML\Graphics\Texture.hpp"
#include "SFML\Graphics\Sprite.hpp"
#include "SpriteComponent.h"
#include "RenderingSystem.h"


int main()
{
	ResourceHolder<sf::Texture, std::string> texturesHolder;

	try
	{
		texturesHolder.Load("GRAVEYARD_BACKGROUND", "resources/images/graveyard_map/BG.png");
		texturesHolder.Load("TILE01", "resources/images/graveyard_map/Tiles/Tile (1).png");
		texturesHolder.Load("TILE02", "resources/images/graveyard_map/Tiles/Tile (2).png");
		texturesHolder.Load("TILE03", "resources/images/graveyard_map/Tiles/Tile (3).png");
		texturesHolder.Load("PLAYER_IDLE", "resources/images/player/Idle (3).png");
	}
	catch (std::runtime_error e)
	{
		std::cout << e.what() << std::endl;
	}

	auto window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1366, 768), "Main window");

	sf::View view1(sf::FloatRect(0, 0, 2000, 1143));

	//view1.zoom(1.5);
	window->setView(view1);

	//Entity creation
	auto rect = std::make_unique<Entity>();

	rect->AddComponent<PositionComponent>(sf::Vector2f(0, 0));
	rect->AddComponent<SpriteComponent>(texturesHolder.Get("GRAVEYARD_BACKGROUND"), RenderLayers::BACK);

	EntitiesVec objVec;
	objVec.push_back(std::move(rect));

	rect = std::make_unique<Entity>();

	rect->AddComponent<PositionComponent>(sf::Vector2f(60, 500));
	rect->AddComponent<SpriteComponent>(texturesHolder.Get("TILE01"), RenderLayers::MIDDLE);
	objVec.push_back(std::move(rect));

	auto player = std::make_unique<Entity>();

	player->AddComponent<PositionComponent>(sf::Vector2f(200, 500));
	player->AddComponent<SpriteComponent>(texturesHolder.Get("PLAYER_IDLE"), RenderLayers::FRONT);
	objVec.push_back(std::move(player));


	//StateMachine creation
	auto stateMachine = std::make_unique<GameStateMachine>();

	//Renderer creation
	auto ren = std::make_unique<RenderingSystem>();

	//Updater creation
	auto upd = std::make_unique<SimpleUpdater>();

	//State creation
	auto runningState = std::make_unique<GameState>(std::move(objVec));

	runningState->AddRenderer(std::move(ren));
	//runningState->AddUpdater(std::move(upd));

	stateMachine->Push(std::move(runningState));

	Engine engine(std::move(window), std::move(stateMachine));

	//Run
	engine.Run();

	system("PAUSE");
}