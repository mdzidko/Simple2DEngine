#pragma once

#include <memory>
#include "core/GameStateMachine.h"
#include "core/Context.h"

class GSMLoader
{
public:
    virtual GameStateMachinePtr Load(Context context) = 0;
};

