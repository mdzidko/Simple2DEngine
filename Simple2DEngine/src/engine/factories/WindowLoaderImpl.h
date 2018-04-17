#pragma once

#include <factories/WindowLoader.h>

class WindowLoaderImpl : public WindowLoader
{
public:
    WindowPtr Load() override;
};
