#include "GSMLoaderImpl.h"
#include "PlayingStateFactory.h"

GameStateMachinePtr GSMLoaderImpl::Load(WorldFactory* worldLoader)
{
    auto stateMachine = std::make_unique<GameStateContext>(worldLoader);

    PlayingStateFactory stateFactory;
    auto palyingState = stateFactory.Create(stateMachine.get());

    stateMachine->Push(std::move(palyingState));

    return stateMachine;
}
