#pragma once

#include <WindowLoader.h>

class WindowLoaderImpl : public WindowLoader
{
public:
    WindowPtr Load() override;
};
