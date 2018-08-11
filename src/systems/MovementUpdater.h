#pragma once

#include "Updater.h"

class MovementUpdater : public Updater
{
public:
    void Update(World *world, GameStateContext *context, float dT) override;

protected:
    bool CheckEntityMach(Entity *entity) override;

};

