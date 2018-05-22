#include <PositionComponent.h>
#include <AnimationComponent.h>
#include "AnimationRenderer.h"

void AnimationRenderer::Refresh()
{
    for (auto& lePair : entitiesMap)
    {
        auto entities = lePair.second;

        entities.erase(remove_if(entities.begin(), entities.end(),
                                 [](Entity* ent) { return !ent->IsAlive(); }), entities.end());
    }
}

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

                          animComp.setPosition(posComp.GetPosition());
                          window->draw(animComp);
                      });
    }
}

bool AnimationRenderer::CheckEntityMach(Entity *entity)
{
    return entity->HasComponent<PositionComponent>() && entity->HasComponent<AnimationComponent>();
}


void AnimationRenderer::AddEntityToContainer(Entity* entity)
{
    const auto& animationComponent = entity->GetComponent<AnimationComponent>();
    LayeredEntitiesMap::iterator lePairIt = entitiesMap.find(animationComponent.renderLayer);

    if (lePairIt == entitiesMap.end())
    {
        auto lePair = std::make_pair(animationComponent.renderLayer, std::vector<Entity*>());

        entitiesMap.insert(lePair);
    }

    auto& entitiesVec = entitiesMap.at(animationComponent.renderLayer);
    entitiesVec.push_back(entity);
}