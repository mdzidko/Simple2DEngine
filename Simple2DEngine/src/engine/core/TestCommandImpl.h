#pragma once

#include "Command.h"

class TestCommandImpl : public Command
{
public:
    void execute(Entity *entity) override;

};

