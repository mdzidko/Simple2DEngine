#include <PositionComponent.h>
#include <MovementComponent.h>
#include <algorithm>
#include <World.h>
#include <StateComponent.h>
#include <CameraComponent.h>
#include "CameraUpdater.h"

void CameraUpdater::Update(World *world, GameStateMachine *context, float dT)
{
    std::for_each(std::begin(entities), std::end(entities),
                  [&](Entity* entity)
                  {
                      auto& pc = entity->GetComponent<PositionComponent>();
                      auto& mc = entity->GetComponent<MovementComponent>();
                      auto& sc = entity->GetComponent<StateComponent>();
                      auto& cc = entity->GetComponent<CameraComponent>();

					  auto newVel = mc.GetVelocity() + (mc.GetAcceleration() * dT);
					  mc.SetVelocity(newVel);

                      auto translation = newVel * dT;

                      auto newPos = pc.GetPosition() + translation;
                      auto offset = cc.GetOffset();

                      auto& view = world->worldView;
                      auto worldWidth = world->GetWorldBounds().width;

                      if(((view.getCenter().x - (view.getSize().x / 2)) + offset.x > newPos.x && sc.GetActiveState() == "MOVE_LEFT" && view.getCenter().x - (view.getSize().x / 2) > 0) ||
                              ((view.getCenter().x + (view.getSize().x / 2)) - offset.x < newPos.x && sc.GetActiveState() == "MOVE_RIGHT" && view.getCenter().x + (view.getSize().x / 2) < worldWidth))
                          view.move(translation);
                  });
}

bool CameraUpdater::CheckEntityMach(Entity *entity)
{
    return entity->HasComponent<PositionComponent>() &&
           entity->HasComponent<MovementComponent>() &&
           entity->HasComponent<CameraComponent>();
}
