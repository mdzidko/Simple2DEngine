#pragma once

#include "core/GameState.h"

class PlayingStateFactory
{
public:
    GameStatePtr Create(Context context);
};
