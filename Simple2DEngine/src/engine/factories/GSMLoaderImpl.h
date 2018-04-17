#pragma once

#include "GSMLoader.h"

class GSMLoaderImpl : public GSMLoader
{
public:
    GameStateMachinePtr Load(Context context) override;
};
