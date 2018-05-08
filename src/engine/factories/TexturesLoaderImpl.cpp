#include <iostream>
#include "TexturesLoaderImpl.h"

void TexturesLoaderImpl::Load(TexturesHolder &texturesHolder)
{
    try
    {
        texturesHolder.Load("BACKGROUND", "resources/images/bg.png");
        texturesHolder.Load("GRASS", "resources/images/tiles/grass.png");
        texturesHolder.Load("GRASS_CLIFF_LEFT", "resources/images/tiles/grassCliffLeft.png");
        texturesHolder.Load("GRASS_CLIFF_RIGHT", "resources/images/tiles/grassCliffRight.png");
        texturesHolder.Load("PLAYER", "resources/images/Player/p3_front.png");
    }
    catch (std::runtime_error e)
    {
        std::cout << e.what() << std::endl;
    }
}
