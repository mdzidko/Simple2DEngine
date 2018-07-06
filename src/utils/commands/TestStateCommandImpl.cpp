#include <iostream>
#include <MovementComponent.h>
#include "TestStateCommandImpl.h"
#include <Entity.h>
#include <AnimationComponent.h>
#include <StateComponent.h>


void TestStateCommandImpl::execute(Entity *entity)
{
	auto& mc = entity->GetComponent<MovementComponent>();
    auto& ac = entity->GetComponent<AnimationComponent>();
    auto& sc = entity->GetComponent<StateComponent>();

    auto activeState = sc.GetActiveState();

    if(activeState == "IDDLE")
    {
        mc.SetVelocity({ 0.f, 0.f });
        ac.PlayAnimation("PLAYER_IDDLE");
    }
    else if(activeState == "MOVE_RIGHT")
    {
        mc.SetVelocity({ 0.15f, 0.f });
        ac.PlayAnimation("PLAYER_WALK");
    }
    else if(activeState == "MOVE_LEFT")
    {
        mc.SetVelocity({ -0.15f, 0.f });
        ac.PlayAnimation("PLAYER_WALK", true);
    }

}

void RightKeyPressedCommand::execute(Entity *entity)
{
    auto& sc = entity->GetComponent<StateComponent>();
    sc.SetActiveState("MOVE_RIGHT");
}

void LeftKeyPressedCommand::execute(Entity *entity)
{
    auto& sc = entity->GetComponent<StateComponent>();
    sc.SetActiveState("MOVE_LEFT");
}

void NoKeyPressedCommand::execute(Entity *entity)
{
    auto& sc = entity->GetComponent<StateComponent>();
    sc.SetActiveState("IDDLE");
}