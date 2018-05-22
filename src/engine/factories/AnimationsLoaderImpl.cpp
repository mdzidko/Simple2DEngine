#include <c++/iostream>
#include "AnimationsLoaderImpl.h"

void AnimationsLoaderImpl::Load(ResourceHolder<Animation, std::string> &resourcesHolder)
{
    try
    {
        resourcesHolder.Load("PLAYER_WALK", "resources/animations/player_walk.json");
    }
    catch (std::runtime_error e)
    {
        std::cout << e.what() << std::endl;
    }
}
