#include <AnimationComponent.h>
#include "AnimationUpdater.h"

void AnimationUpdater::Update(World *world, GameStateContext *context, float dT)
{
    std::for_each(std::begin(entities), std::end(entities),
                  [&](Entity* entity)
                  {
                      auto& ac = entity->GetComponent<AnimationComponent>();

                      ac.Update(dT);
                  });
}

bool AnimationUpdater::CheckEntityMach(Entity *entity)
{
    return entity->HasComponent<AnimationComponent>();
}
