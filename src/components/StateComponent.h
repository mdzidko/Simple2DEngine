#pragma once

#include "CommandComponent.h"

class StateComponent : public CommandComponent
{
public:
    std::string GetActiveState();

    void SetActiveState(std::string activeState);

private:
    std::string activeState{""};
};