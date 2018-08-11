#pragma once

#include <memory>
#include "GameStateContext.h"
#include "Context.h"

class GSMLoader
{
public:
    virtual GameStateMachinePtr Load(WorldFactory* worldLoader) = 0;
};

