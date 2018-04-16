#include <RenderingSystem.h>
#include <SimpleUpdater.h>
#include "PlayingStateFactory.h"

GameStatePtr PlayingStateFactory::Create()
{
    auto state = std::make_unique<GameState>();

    auto renderer = std::make_unique<RenderingSystem>();
    auto updater = std::make_unique<SimpleUpdater>();

    state->AddRenderer(std::move(renderer));
    state->AddUpdater(std::move(updater));

    return state;
}
