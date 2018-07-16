#pragma once

#include "Updater.h"

class CameraUpdater : public Updater
{
public:
    void Update(World *world, GameStateMachine *context, float dT) override;

protected:
    bool CheckEntityMach(Entity *entity) override;

};

