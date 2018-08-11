#pragma once

#include "GSMLoader.h"

class GSMLoaderImpl : public GSMLoader
{
public:
    GameStateMachinePtr Load(WorldFactory* worldLoader) override;
};
