#include <algorithm>
#include "Updater.h"

void Updater::Refresh()
{
    entities.erase(std::remove_if(entities.begin(), entities.end(),
                             [](Entity* ent) { return !ent->IsAlive(); }), entities.end());
}

void Updater::AddEntityToContainer(Entity *entity)
{
    entities.push_back(entity);
}