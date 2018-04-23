#include <RenderingSystem.h>
#include <InputUpdater.h>
#include "PlayingStateFactory.h"
#include "WorldLoaderImpl.h"

GameStatePtr PlayingStateFactory::Create(Context context)
{
    auto state = std::make_unique<GameState>(context);

    auto renderer = std::make_unique<RenderingSystem>();
    auto updater = std::make_unique<InputUpdater>();

    state->AddRenderer(std::move(renderer));
    state->AddUpdater(std::move(updater));

    WorldLoaderImpl worldLoader;
    state->LoadWorld(&worldLoader);

    return state;
}
