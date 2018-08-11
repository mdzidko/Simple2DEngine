#pragma once

#include "GameState.h"

class PlayingStateFactory
{
public:
    GameStatePtr Create(GameStateContext* context);
};
