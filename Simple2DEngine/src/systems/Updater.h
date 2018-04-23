#pragma once

#include "System.h"
class GameStateMachine;
class World;

class Updater : public System
{
public:
	virtual void Update(World* world, GameStateMachine* context, float dT) = 0;
	void Refresh() override;

protected:
	void AddEntityToContainer(Entity *entity) override;
	std::vector<Entity*> entities;
};

using UpdaterPtr = std::unique_ptr<Updater>;
