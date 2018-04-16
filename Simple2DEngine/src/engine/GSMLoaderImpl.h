#ifndef SIMPLE2DENGINE_GAMESTATESLOADERIMPL_H
#define SIMPLE2DENGINE_GAMESTATESLOADERIMPL_H


#include "GSMLoader.h"

class GSMLoaderImpl : public GSMLoader
{
public:
    GameStateMachinePtr Load() override;
};


#endif //SIMPLE2DENGINE_GAMESTATESLOADERIMPL_H
