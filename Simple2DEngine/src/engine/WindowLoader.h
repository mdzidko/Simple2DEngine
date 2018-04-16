//
// Created by Michał on 2018-04-13.
//

#ifndef SIMPLE2DENGINE_WINDOWLOADER_H
#define SIMPLE2DENGINE_WINDOWLOADER_H

#include <memory>

using WindowPtr = std::unique_ptr<sf::RenderWindow>;

class WindowLoader
{
public:
    virtual WindowPtr Load() = 0;
};


#endif //SIMPLE2DENGINE_WINDOWLOADER_H
