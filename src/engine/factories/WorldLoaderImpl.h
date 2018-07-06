#pragma once

#include "WorldLoader.h"
#include "Context.h"

class WorldLoaderImpl : public WorldLoader
{
public:
    WorldPtr Load(Context context, GameState* gameState) override;

private:
    void LoadPlayer(World* world, sf::Vector2f pos, Context& context);
    void LoadEnemy(World* world, sf::Vector2f pos, Context& context);
    void LoadMapElement(World* world, std::string textureName, sf::Vector2f pos, sf::Vector2f size, bool repeated, Context &context);
};
