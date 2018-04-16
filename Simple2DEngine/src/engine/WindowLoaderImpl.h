//
// Created by Michał on 2018-04-13.
//

#ifndef SIMPLE2DENGINE_WINDOWLOADERIMPL_H
#define SIMPLE2DENGINE_WINDOWLOADERIMPL_H

#include <WindowLoader.h>

class WindowLoaderImpl : public WindowLoader
{
public:
    WindowPtr Load() override;
};


#endif //SIMPLE2DENGINE_WINDOWLOADERIMPL_H
