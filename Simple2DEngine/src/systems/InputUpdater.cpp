#include <InputComponent.h>
#include "InputUpdater.h"

void InputUpdater::Update(World *world, GameStateMachine *context, float dT)
{


}

bool InputUpdater::CheckEntityMach(Entity *entity)
{
    return entity->HasComponent<InputComponent>();
}
