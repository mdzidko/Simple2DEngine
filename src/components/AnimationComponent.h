#pragma  once

#include <Component.h>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <map>
#include "../utils/animation/Animation.h"

class AnimationComponent : public Component, public sf::Transformable, public sf::Drawable
{
public:
    AnimationComponent(float frameTime = 0.1f, RenderLayers layer = RenderLayers::FRONT);

    void AddAnimation(std::string name, const Animation* animation);
    void PlayAnimation(std::string animation, bool flipped = false);

    void Update(float deltaTime);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    RenderLayers renderLayer;

private:
    void setFrame(std::size_t newFrame, bool resetTime = true);

    std::map<std::string, const Animation*> animationsMap;
    const Animation* currentAnimation{nullptr};
    float frameTime{0.0f};
    float currentTime{0.0f};
    std::size_t currentFrame{0};
    bool flipped {false};

    const sf::Texture* texture;
    sf::Vertex vertices[4];
};

