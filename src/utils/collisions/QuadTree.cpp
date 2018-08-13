#include "QuadTree.h"

QuadTree::QuadTree(int _level, int _posX, int _posY, int _width, int _height)
{
    level = _level;
    bounds.positionX = _posX;
    bounds.positionY = _posY;
    bounds.width = _width;
    bounds.height = _height;
}


QuadTree::~QuadTree()
{
    clear();
}


void QuadTree::clear()
{
    objects.clear();

    for (auto& n : nodes)
        n->clear();

    nodes.clear();
}


bool QuadTree::hasChildren()
{
    return nodes.size() > 0;
}


void QuadTree::split()
{
    int subWidth = (int)(bounds.width / 2);
    int subHeight = (int)(bounds.height / 2);
    int x = (int)bounds.positionX;
    int y = (int)bounds.positionY;

    nodes.push_back(std::make_unique<QuadTree>(level + 1, x + subWidth, y, subWidth, subHeight));
    nodes.push_back(std::make_unique<QuadTree>(level + 1, x, y, subWidth, subHeight));
    nodes.push_back(std::make_unique<QuadTree>(level + 1, x, y + subHeight, subWidth, subHeight));
    nodes.push_back(std::make_unique<QuadTree>(level + 1, x + subWidth, y + subHeight, subWidth, subHeight));
}


int QuadTree::getIndex(Body* _body)
{
    int index = -1;
    Rectangle boundBox = _body->boundBox;

    double verticalMidpoint = bounds.positionX + (bounds.width / 2);
    double horizontalMidpoint = bounds.positionY + (bounds.height / 2);

    bool topQuadrant = (boundBox.positionY < horizontalMidpoint && boundBox.positionY + boundBox.height < horizontalMidpoint);
    bool bottomQuadrant = (boundBox.positionY > horizontalMidpoint);

    if (boundBox.positionX < verticalMidpoint && boundBox.positionX + boundBox.width < verticalMidpoint)
    {
        if (topQuadrant)
            index = 1;
        else if (bottomQuadrant)
            index = 2;
    }
    else if (boundBox.positionX > verticalMidpoint)
    {
        if (topQuadrant)
            index = 0;
        else if (bottomQuadrant)
            index = 3;
    }

    return index;
}


void QuadTree::insert(Body* _body)
{
    if (hasChildren())
    {
        int index = getIndex(_body);

        if (index != -1)
        {
            nodes[index]->insert(_body);
            return;
        }
    }

    objects.push_back(_body);

    if (objects.size() > MAX_OBJECTS && level < MAX_LEVELS)
    {
        if (!hasChildren())
            split();

        int index;
        Body* currentBody;

        for (unsigned i = 0; i < objects.size();)
        {
            index = getIndex(objects.at(i));
            if (index != -1)
            {
                currentBody = objects.at(i);
                objects.erase(objects.begin() + i);
                nodes[index]->insert(currentBody);
            }
            else
                i++;
        }
    }
}


std::vector<Body*> QuadTree::retrieve(std::vector<Body*>& _returnObjects, Body* _body)
{
    int index = getIndex(_body);
    if (index != -1 && hasChildren())
        nodes[index]->retrieve(_returnObjects, _body);

    for (auto& o : objects)
        _returnObjects.push_back(o);

    return _returnObjects;
}


std::vector<Body*> QuadTree::retrievePossibleCollisions(Body* _body)
{
    std::vector<Body*> possibleCollisions;
    return retrieve(possibleCollisions, _body);
}

void QuadTree::preOrderTraversal() {
    for (int i = 0; i < level; i++) {
        std::cout << "\t";
    }
    std::cout << "Entity count: " << objects.size() << "\n";
    for (int i = 0; i < level; i++) {
        std::cout << "\t";
    }
    std::cout << "Bounds: " << bounds.positionX << ", " << bounds.positionY << ", " << bounds.width << ", " << bounds.height << "\n";
    for (auto& i : nodes) {
        i->preOrderTraversal();
    }
}