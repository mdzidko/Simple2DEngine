#ifndef SIMPLE2DENGINE_TEXTURESLOADERIMPL_H
#define SIMPLE2DENGINE_TEXTURESLOADERIMPL_H

#include "TexturesLoader.h"

class TexturesLoaderImpl : public TexturesLoader
{
public:
    void Load(TexturesHolder &texturesHolder) override;

};

#endif //SIMPLE2DENGINE_TEXTURESLOADERIMPL_H
