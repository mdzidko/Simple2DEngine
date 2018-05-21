#include <PositionComponent.h>
#include <AnimationComponent.h>
#include "AnimationRenderer.h"

void AnimationRenderer::Render(sf::RenderWindow *window, float interpolation)
{
    for (auto& lePair : entitiesMap)
    {
        auto entities = lePair.second;

        std::for_each(std::begin(entities), std::end(entities),
                      [&](Entity* entity)
                      {
                          auto& animComp = entity->GetComponent<AnimationComponent>();
                          auto& posComp = entity->GetComponent<PositionComponent>();

                          window->draw(animComp);
                      });
    }
}

bool AnimationRenderer::CheckEntityMach(Entity *entity)
{
    return entity->HasComponent<PositionComponent>() && entity->HasComponent<AnimationComponent>();
}
