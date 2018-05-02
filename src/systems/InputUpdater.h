#pragma once

#include "Updater.h"

class InputUpdater : public Updater
{
public:
    void Update(World *world, GameStateMachine *context, float dT) override;

private:
    bool CheckEntityMach(Entity *entity) override;
	std::string GetPressedKey();
};

