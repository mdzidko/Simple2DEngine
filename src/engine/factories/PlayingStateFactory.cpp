#include <SpritesRenderer.h>
#include <InputUpdater.h>
#include <MovementUpdater.h>
#include <AnimationRenderer.h>
#include <AnimationUpdater.h>
#include <StateUpdater.h>
#include "PlayingStateFactory.h"
#include "WorldLoaderImpl.h"

GameStatePtr PlayingStateFactory::Create(Context context)
{
    auto state = std::make_unique<GameState>(context);

    auto renderer = std::make_unique<SpritesRenderer>();
    state->AddRenderer(std::move(renderer));

    auto animRenderer = std::make_unique<AnimationRenderer>();
    state->AddRenderer(std::move(animRenderer));

    auto inputUpdater = std::make_unique<InputUpdater>();
    state->AddUpdater(std::move(inputUpdater));

    auto stateUpdater = std::make_unique<StateUpdater>();
    state->AddUpdater(std::move(stateUpdater));

    auto movementUpdater = std::make_unique<MovementUpdater>();
    state->AddUpdater(std::move(movementUpdater));

    auto animationUpdater = std::make_unique<AnimationUpdater>();
    state->AddUpdater(std::move(animationUpdater));

    WorldLoaderImpl worldLoader;
    state->LoadWorld(&worldLoader);

    return state;
}
