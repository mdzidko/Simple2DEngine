#pragma once

#include <memory>
#include "GameStateMachine.h"
#include "Context.h"

class GSMLoader
{
public:
    virtual GameStateMachinePtr Load(Context context) = 0;
};

