#pragma once

#include "Command.h"

class TestStateCommandImpl : public Command
{
public:
    void execute(Entity *entity) override;
};

class RightKeyPressedCommand : public Command
{
public:
    void execute(Entity *entity) override;
};

class LeftKeyPressedCommand : public Command
{
public:
    void execute(Entity *entity) override;
};

class NoKeyPressedCommand : public Command
{
public:
    void execute(Entity *entity) override;
};