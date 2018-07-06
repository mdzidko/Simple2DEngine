#include <c++/iostream>
#include "AnimationsLoaderImpl.h"

void AnimationsLoaderImpl::Load(ResourceHolder<Animation, std::string> &resourcesHolder)
{
    try
    {
        resourcesHolder.Load("PLAYER_WALK", "resources/animations/player_walk.json");
        resourcesHolder.Load("PLAYER_IDDLE", "resources/animations/player_iddle.json");
        resourcesHolder.Load("SLIME_WALK", "resources/animations/slime_walk.json");
        resourcesHolder.Load("FLY", "resources/animations/fly.json");
    }
    catch (std::runtime_error e)
    {
        std::cout << e.what() << std::endl;
    }
}
