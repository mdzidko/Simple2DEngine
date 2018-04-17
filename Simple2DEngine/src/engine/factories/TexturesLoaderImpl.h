#pragma once

#include "TexturesLoader.h"

class TexturesLoaderImpl : public TexturesLoader
{
public:
    void Load(TexturesHolder &texturesHolder) override;

};
