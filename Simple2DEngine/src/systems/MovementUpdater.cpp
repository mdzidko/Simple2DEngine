#include <PositionComponent.h>
#include <MovementComponent.h>
#include <algorithm>
#include "MovementUpdater.h"

void MovementUpdater::Update(World *world, GameStateMachine *context, float dT)
{
    std::for_each(std::begin(entities), std::end(entities),
                  [&](Entity* entity)
                  {
                      auto& pc = entity->GetComponent<PositionComponent>();
                      auto& mc = entity->GetComponent<MovementComponent>();

					  auto newVel = mc.GetVelocity() + (mc.GetAcceleration() * dT);
					  mc.SetVelocity(newVel);

                      auto newPos = pc.GetPosition() + (newVel * dT);
                      pc.SetPosition(newPos);
                  });
}

bool MovementUpdater::CheckEntityMach(Entity *entity)
{
    return entity->HasComponent<PositionComponent>() && entity->HasComponent<MovementComponent>();
}
