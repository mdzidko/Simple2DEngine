#pragma once

#include "Updater.h"

class StateUpdater : public Updater
{
public:
    void Update(World *world, GameStateContext *context, float dT) override;

protected:
    bool CheckEntityMach(Entity *entity) override;
};


