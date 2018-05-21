#pragma once

#include "ResourcesLoader.h"

class AnimationsLoaderImpl : public AnimationsLoader
{
public:
    void Load(ResourceHolder<Animation, std::string> &resourcesHolder) override;

};
