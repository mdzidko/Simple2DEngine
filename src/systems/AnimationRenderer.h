#pragma once

#include "Renderer.h"

class AnimationRenderer : public Renderer
{
public:
    virtual void Render(sf::RenderWindow* window, float interpolation) override;
    virtual void Refresh() override;

protected:
    LayeredEntitiesMap entitiesMap;

    virtual bool CheckEntityMach(Entity* entity) override;
    virtual void AddEntityToContainer(Entity* entity) override;
};

