#include "PausedStateFactory.h"

GameStatePtr PausedStateFactory::Create()
{
    auto state = std::make_unique<GameState>();

    return state;
}