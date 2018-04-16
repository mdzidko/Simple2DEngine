#ifndef SIMPLE2DENGINE_GAMESTATESLOADER_H
#define SIMPLE2DENGINE_GAMESTATESLOADER_H

#include <memory>
#include "GameStateMachine.h"

class GSMLoader
{
public:
    virtual GameStateMachinePtr Load() = 0;
};


#endif //SIMPLE2DENGINE_GAMESTATESLOADER_H
