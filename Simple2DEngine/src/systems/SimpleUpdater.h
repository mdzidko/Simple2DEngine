#pragma once

#include <World.h>
#include "Updater.h"
class GameStateMachine;

class SimpleUpdater : public Updater
{
public:
	virtual void Update(World* world, GameStateMachine* context, float dT) override;

	virtual void Refresh() override;

protected:
	std::vector<Entity*> entities;

	virtual bool CheckEntityMach(Entity* entity) override;
	virtual void AddEntityToContainer(Entity* entity) override;
};

