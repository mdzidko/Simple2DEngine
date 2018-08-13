#pragma once

#include <vector>
#include <array>
#include <memory>
#include <iostream>
#include "Body.h"

class QuadTree
{
public:
    QuadTree(int _level, int _posX, int _posY, int _width, int _height);
    ~QuadTree();

    void clear();
    void insert(Body* _body);
    std::vector<Body*> QuadTree::retrievePossibleCollisions(Body* _body);

    bool hasChildren();

    Rectangle& getBounds() { return bounds; };
    std::vector<std::unique_ptr<QuadTree>>& getNodes() { return nodes; };

    void preOrderTraversal();

private:
    const int MAX_LEVELS = 5;
    const int MAX_OBJECTS = 10;

    int level{ 0 };
    std::vector<Body*> objects;
    Rectangle bounds;
    std::vector<std::unique_ptr<QuadTree>> nodes;

    void split();
    int getIndex(Body* _body);
    std::vector<Body*> retrieve(std::vector<Body*>& _returnObjects, Body* _body);
};
