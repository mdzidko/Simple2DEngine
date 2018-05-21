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
    AnimationComponent(float frameTime = 0.1f);

    void AddAnimation(std::string name, Animation* animation);
    void PlayAnimation(std::string animation, bool flipped = false);

    void Update(float deltaTime);
    void Draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    void setFrame(std::size_t newFrame, bool resetTime = true);

    std::map<std::string, Animation*> animationsMap;
    Animation* currentAnimation;
    float frameTime;
    float currentTime;
    std::size_t currentFrame;
    bool flipped {false};

    const sf::Texture* texture;
    sf::Vertex vertices[4];
};

