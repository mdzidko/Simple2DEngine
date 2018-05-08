#pragma once

#include "Renderer.h"

class AnimationRenderer : public Renderer
{
public:
    void Render(sf::RenderWindow *window, float interpolation) override;

protected:
    bool CheckEntityMach(Entity *entity) override;
};

