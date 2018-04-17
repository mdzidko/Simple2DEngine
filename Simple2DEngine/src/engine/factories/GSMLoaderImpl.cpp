#include "GSMLoaderImpl.h"
#include "PlayingStateFactory.h"

GameStateMachinePtr GSMLoaderImpl::Load(Context context)
{
    auto stateMachine = std::make_unique<GameStateMachine>(context);

    PlayingStateFactory stateFactory;
    auto palyingState = stateFactory.Create(context);

    stateMachine->Push(std::move(palyingState));

    return stateMachine;
}
