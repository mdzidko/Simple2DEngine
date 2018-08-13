#include "CollisionSystem.h"



void CollisionSystem::update()
{
    updateColliderPosition();

    quadtree->clear();

    for (auto e : entities)
    {
        if (e->HasComponent<CollisionComponent>())
        {
            CollisionComponent& cc = e->GetComponent<CollisionComponent>();
            quadtree->insert(&cc);
        }
    }

    for (auto e : entities)
    {
        if (e->HasComponent<CollisionComponent>())
        {
            auto cc = e->GetComponent<CollisionComponent>();
            auto possibleCollisions = quadtree->retrievePossibleCollisions(&cc);

            for (auto b : possibleCollisions)
                checkCollision(&cc, (CollisionComponent*)(b));
        }
    }
}


void CollisionSystem::updateColliderPosition()
{
    for (auto& e : entities){
        auto& pc = e->GetComponent<PositionComponent>();
        auto& cc = e->GetComponent<CollisionComponent>();

        cc.setPosition(pc.GetPosition());
    }
}


void CollisionSystem::checkCollision(CollisionComponent* _en1, CollisionComponent* _en2)
{
    if (_en1->boundBox.positionX == _en2->boundBox.positionX &&
        _en1->boundBox.positionY == _en2->boundBox.positionY)
        return;

    if (!isIntersecting(_en1, _en2))
        return;

    std::string handler = _en1->getHandler();
   /* if (handler != "")
    {
        EntityHandler eh1(&_en1->getParent());
        EntityHandler eh2(&_en2->getParent());

        LuaRef fun = lua->getLuaGlobal(_en1->getHandler().c_str());
        fun(eh1, eh2);
    }*/
}


bool CollisionSystem::isIntersecting(CollisionComponent* _cc1, CollisionComponent* _cc2)
{
    return _cc1->right() >= _cc2->left() && _cc1->left() <= _cc2->right() &&
           _cc1->top() <= _cc2->bottom() && _cc1->bottom() >= _cc2->top();
}