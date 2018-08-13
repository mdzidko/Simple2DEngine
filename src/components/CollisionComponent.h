#pragma once

#include "Entity.h"
#include "../utils/collisions/Body.h"
#include <SFML/System.hpp>
#include <iostream>
#include <map>

class CollisionComponent : public Component, public Body
{
public:
    CollisionComponent() = default;

    CollisionComponent(const std::map<std::string, std::string>& _paramsMap)
    {
        for (auto pm : _paramsMap)
        {
            auto key = pm.first;
            auto value = pm.second;

            if (key == "positionX")
                boundBox.positionX = stoi(value);
            else if (key == "positionY")
                boundBox.positionY = stoi(value);
            else if (key == "width")
                boundBox.width = stoi(value);
            else if (key == "height")
                boundBox.height = stoi(value);
            else if (key == "handler")
                collideFunction = value;
        }
    }

    std::string getHandler()
    {
        return collideFunction;
    }

    sf::Vector2f getPosition()
    {
        sf::Vector2f pos( boundBox.positionX, boundBox.positionY );
        return pos;
    }

    void setPosition(sf::Vector2f _position)
    {
        boundBox.positionX = _position.x;
        boundBox.positionY = _position.y;
    }

    void setBoundBox(sf::Vector2i _size)
    {
        boundBox.width = _size.x;
        boundBox.height = _size.y;
    }

private:
    string collideFunction;
};