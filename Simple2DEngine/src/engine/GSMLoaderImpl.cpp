#include "GSMLoaderImpl.h"
#include "MenuStateFactory.h"

GameStateMachinePtr GSMLoaderImpl::Load()
{
    auto stateMachine = std::make_unique<GameStateMachine>();

    MenuStateFactory menuStateFactory;
    auto menuState = menuStateFactory.Create();

    stateMachine->Push(std::move(menuState));

    return stateMachine;
}
