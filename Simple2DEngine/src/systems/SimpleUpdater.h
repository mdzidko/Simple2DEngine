#pragma once

#include "System.h"
class GameStateMachine;

class SimpleUpdater : public System
{
public:
	virtual void Update(GameStateMachine* context, float dT);

	virtual void Refresh() override;

protected:
	std::vector<Entity*> entities;

	virtual bool CheckEntityMach(Entity* entity) override;
	virtual void AddEntityToContainer(Entity* entity) override;
};

