//
// Created by Michał on 2018-04-13.
//

#include <iostream>
#include "TexturesLoaderImpl.h"

void TexturesLoaderImpl::Load(TexturesHolder &texturesHolder)
{
    try
    {
        texturesHolder.Load("GRAVEYARD_BACKGROUND", "resources/images/graveyard_map/BG.png");
        texturesHolder.Load("TILE01", "resources/images/graveyard_map/Tiles/Tile (1).png");
        texturesHolder.Load("TILE02", "resources/images/graveyard_map/Tiles/Tile (2).png");
        texturesHolder.Load("TILE03", "resources/images/graveyard_map/Tiles/Tile (3).png");
        texturesHolder.Load("PLAYER_IDLE", "resources/images/player/Idle (3).png");
    }
    catch (std::runtime_error e)
    {
        std::cout << e.what() << std::endl;
    }
}
