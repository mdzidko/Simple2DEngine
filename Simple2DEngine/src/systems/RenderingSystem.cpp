#include "RenderingSystem.h"
#include "PositionComponent.h"


void RenderingSystem::Refresh()
{
	for (auto& lePair : entitiesMap)
	{
		auto entities = lePair.second;

		entities.erase(remove_if(entities.begin(), entities.end(),
			[](Entity* ent) { return !ent->IsAlive(); }), entities.end());
	}
}

void RenderingSystem::Update(sf::RenderWindow* window, float interpolation)
{
	window->clear();

	for (auto& lePair : entitiesMap)
	{
		auto entities = lePair.second;

		std::for_each(std::begin(entities), std::end(entities),
			[&](Entity* entity)
		{
			auto& sprComp = entity->GetComponent<SpriteComponent>();
			auto& posComp = entity->GetComponent<PositionComponent>();

			auto& sprite = sprComp.sprite;
			auto texture = const_cast<sf::Texture*>(sprite.getTexture());

			texture->setSmooth(true);

			sprite.setPosition(posComp.position);

			window->draw(sprite);
		});
	}

	window->display();
}

bool RenderingSystem::CheckEntityMach(Entity* entity)
{
	bool hasCorrectComponents;

	hasCorrectComponents = entity->HasComponent<SpriteComponent>() 
		&& entity->HasComponent<PositionComponent>();

	return hasCorrectComponents;
}

void RenderingSystem::AddEntityToContainer(Entity* entity)
{
	const auto& spriteComponent = entity->GetComponent<SpriteComponent>();
	LayeredEntitiesMap::iterator lePairIt = entitiesMap.find(spriteComponent.renderLayer);

	if (lePairIt == entitiesMap.end())
	{
		auto lePair = std::make_pair(spriteComponent.renderLayer, std::vector<Entity*>());
		
		entitiesMap.insert(lePair);
	}

	auto& entitiesVec = entitiesMap.at(spriteComponent.renderLayer);
	entitiesVec.push_back(entity);
}
