#pragma once

#include "ResourcesLoader.h"

class TexturesLoaderImpl : public TexturesLoader
{
public:
    void Load(TexturesHolder &texturesHolder) override;

};
