#ifndef SIMPLE2DENGINE_PLAYINGSTATEFACTORY_H
#define SIMPLE2DENGINE_PLAYINGSTATEFACTORY_H

#include "GameState.h"

class PlayingStateFactory
{
public:
    GameStatePtr Create();
};

#endif //SIMPLE2DENGINE_PLAYINGSTATEFACTORY_H
