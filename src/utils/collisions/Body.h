#pragma once

struct Rectangle
{
    int positionX{ 0 };
    int positionY{ 0 };

    int width{ 0 };
    int height{ 0 };
};

struct Body
{
    Rectangle boundBox;
    int rotation{ 0 };

    int left()
    {
        return boundBox.positionX - (boundBox.width / 2);
    };

    int right()
    {
        return boundBox.positionX + (boundBox.width / 2);
    };

    int top()
    {
        return boundBox.positionY - (boundBox.height / 2);
    };

    int bottom()
    {
        return boundBox.positionY + (boundBox.height / 2);
    };
};