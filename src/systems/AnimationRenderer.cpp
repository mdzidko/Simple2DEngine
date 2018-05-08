#include <PositionComponent.h>
#include <AnimationComponent.h>
#include "AnimationRenderer.h"

void AnimationRenderer::Render(sf::RenderWindow *window, float interpolation)
{

}

bool AnimationRenderer::CheckEntityMach(Entity *entity)
{
    return entity->HasComponent<PositionComponent>() && entity->HasComponent<AnimationComponent>();
}
