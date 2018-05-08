#include "StateComponent.h"


void StateComponent::SetActiveState(std::string activeState)
{
    this->activeState = activeState;
}

std::string StateComponent::GetActiveState() {
    return activeState;
}
