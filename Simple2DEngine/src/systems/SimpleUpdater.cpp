#include "SimpleUpdater.h"
#include "PositionComponent.h"
#include "SFML\Window\Keyboard.hpp"
#include "GameStateMachine.h"



void SimpleUpdater::Update(World* world, GameStateMachine* context, float dT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		context->Pop();
	}

	std::for_each(std::begin(entities), std::end(entities),
		[&](Entity* entity)
	{
		/*std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(-0.2, 0.2);

		auto meanx = dis(gen) * dT;
		auto meany = dis(gen) * dT;

		auto& posComp = entity->GetComponent<PositionComponent>();

		posComp.position += sf::Vector2f(meanx, meany);*/
	});
}

void SimpleUpdater::Refresh()
{
	entities.erase(remove_if(entities.begin(), entities.end(),
		[](Entity* ent) { return !ent->IsAlive(); }), entities.end());
}

bool SimpleUpdater::CheckEntityMach(Entity* entity)
{
	return true;
}

void SimpleUpdater::AddEntityToContainer(Entity* entity)
{
	entities.push_back(entity);
}

