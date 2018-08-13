#pragma once

#include <algorithm>
#include <iterator>
#include <CollisionComponent.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include "PositionComponent.h"
#include "Updater.h"
#include "../utils/collisions/QuadTree.h"
#include "../lua/core/LuaHandler.h"

class CollisionSystem : public Updater
{
public:
    CollisionSystem(sf::RenderWindow* _window, QuadTree* _quadtree, LuaHandler* _lua) : window{ _window }, quadtree{ _quadtree }, lua{ _lua }{};

    virtual void update();

private:
    QuadTree* quadtree;

    sf::RenderWindow* window;

    LuaHandler* lua = nullptr;

    void checkCollision(CollisionComponent* _en1, CollisionComponent* _en2);
    bool isIntersecting(CollisionComponent* _cc1, CollisionComponent* _cc2);

    void updateColliderPosition();

    float const left(CollisionComponent& _cc);
    float const right(CollisionComponent& _cc);
    float const top(CollisionComponent& _cc);
    float const bottom(CollisionComponent& _cc);
};
