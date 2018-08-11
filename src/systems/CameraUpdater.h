#pragma once

#include "Updater.h"

class CameraUpdater : public Updater
{
public:
    void Update(World *world, GameStateContext *context, float dT) override;

protected:
    bool CheckEntityMach(Entity *entity) override;

};

