#include <iostream>
#include "TexturesLoaderImpl.h"

void TexturesLoaderImpl::Load(TexturesHolder &texturesHolder)
{
    try
    {
        texturesHolder.Load("BACKGROUND", "resources/images/bg.png");
        texturesHolder.Load("GRASS_MID", "resources/images/Tiles/grassMid.png");
        texturesHolder.Load("GRASS_LEFT", "resources/images/Tiles/grassLeft.png");
        texturesHolder.Load("GRASS_RIGHT", "resources/images/Tiles/grassRight.png");
        texturesHolder.Load("FENCE", "resources/images/Tiles/fence.png");
        texturesHolder.Load("FENCE_BROKEN", "resources/images/Tiles/fenceBroken.png");
        texturesHolder.Load("BOX", "resources/images/Tiles/box.png");
        texturesHolder.Load("BRIDGE", "resources/images/Tiles/bridge.png");
        texturesHolder.Load("SIGN_RIGHT", "resources/images/Tiles/signRight.png");
        texturesHolder.Load("SIGN_EXIT", "resources/images/Tiles/signExit.png");
        texturesHolder.Load("WATER", "resources/images/Tiles/liquidWater.png");
        texturesHolder.Load("WATER_TOP", "resources/images/Tiles/liquidWaterTop_mid.png");

        texturesHolder.Load("BUSH", "resources/images/Items/bush.png");
        texturesHolder.Load("PLANT", "resources/images/Items/plant.png");
        texturesHolder.Load("PLANT_PURPLE", "resources/images/Items/plantPurple.png");
        texturesHolder.Load("ROCK", "resources/images/Items/rock.png");
        texturesHolder.Load("STAR", "resources/images/Items/star.png");
        texturesHolder.Load("MUSHROOM_RED", "resources/images/Items/mushroomRed.png");
        texturesHolder.Load("MUSHROOM_BROWN", "resources/images/Items/mushroomBrown.png");
        texturesHolder.Load("CLOUD_1", "resources/images/Items/cloud1.png");
        texturesHolder.Load("CLOUD_2", "resources/images/Items/cloud2.png");
        texturesHolder.Load("CLOUD_3", "resources/images/Items/cloud3.png");
    }
    catch (std::runtime_error e)
    {
        std::cout << e.what() << std::endl;
    }
}
