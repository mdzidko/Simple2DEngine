#include <RenderingSystem.h>
#include <InputUpdater.h>
#include <MovementUpdater.h>
#include "PlayingStateFactory.h"
#include "WorldLoaderImpl.h"

GameStatePtr PlayingStateFactory::Create(Context context)
{
    auto state = std::make_unique<GameState>(context);

    auto renderer = std::make_unique<RenderingSystem>();
    state->AddRenderer(std::move(renderer));

    auto inputUpdater = std::make_unique<InputUpdater>();
    state->AddUpdater(std::move(inputUpdater));

    auto movementUpdater = std::make_unique<MovementUpdater>();
    state->AddUpdater(std::move(movementUpdater));

    WorldLoaderImpl worldLoader;
    state->LoadWorld(&worldLoader);

    return state;
}
