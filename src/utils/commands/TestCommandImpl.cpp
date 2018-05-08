#include <iostream>
#include <MovementComponent.h>
#include "TestCommandImpl.h"
#include <Entity.h>


void TestCommandImpl::execute(Entity *entity)
{
	auto& mc = entity->GetComponent<MovementComponent>();

	mc.SetAcceleration({ 0.002f, 0 });
}
