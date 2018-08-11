#include <StateComponent.h>
#include <algorithm>
#include "StateUpdater.h"

void StateUpdater::Update(World *world, GameStateContext *context, float dT)
{
    std::for_each(std::begin(entities), std::end(entities),
                  [&](Entity* entity)
    {
        auto& sc = entity->GetComponent<StateComponent>();
        auto state = sc.GetActiveState();

        sc.ExecuteCommand(state);
    });
}

bool StateUpdater::CheckEntityMach(Entity *entity)
{
    return entity->HasComponent<StateComponent>();
}
