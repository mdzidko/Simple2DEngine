#pragma once

#include "Updater.h"

class InputUpdater : public Updater
{
public:
    void Update(World *world, GameStateContext *context, float dT) override;

private:
    bool CheckEntityMach(Entity *entity) override;
	std::string GetPressedKey();
};

