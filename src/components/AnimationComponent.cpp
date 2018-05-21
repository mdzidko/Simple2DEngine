#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(float frameTime)
{
    this->frameTime = frameTime;
}

void AnimationComponent::AddAnimation(std::string name, Animation* animation)
{
    animationsMap.insert({name, animation});
}

void AnimationComponent::PlayAnimation(std::string animation, bool flipped)
{
    auto animationIt = animationsMap.find(animation);
    currentAnimation = animationIt->second;

    texture = currentAnimation->getSpriteSheet();
    currentFrame = 0;
    setFrame(currentFrame);

    this->flipped = flipped;
}

void AnimationComponent::setFrame(std::size_t newFrame, bool resetTime)
{
    if (currentAnimation)
    {
        sf::IntRect rect = currentAnimation->getFrame(newFrame);

        vertices[0].position = sf::Vector2f(0.f, 0.f);
        vertices[1].position = sf::Vector2f(0.f, static_cast<float>(rect.height));
        vertices[2].position = sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height));
        vertices[3].position = sf::Vector2f(static_cast<float>(rect.width), 0.f);

        float left = static_cast<float>(rect.left) + 0.0001f;
        float right = left + static_cast<float>(rect.width);
        float top = static_cast<float>(rect.top);
        float bottom = top + static_cast<float>(rect.height);

        vertices[0].texCoords = sf::Vector2f(left, top);
        vertices[1].texCoords = sf::Vector2f(left, bottom);
        vertices[2].texCoords = sf::Vector2f(right, bottom);
        vertices[3].texCoords = sf::Vector2f(right, top);
    }

    if (resetTime)
        currentTime = 0.0f;
}

void AnimationComponent::Update(float deltaTime)
{
    if (currentAnimation)
    {
        currentTime += deltaTime;

        if (currentTime >= frameTime)
        {
            currentTime = 0.0f;

            if (currentFrame + 1 < currentAnimation->getSize())
                currentFrame++;
            else
                currentFrame = 0;

            setFrame(currentFrame, false);
        }
    }
}

void AnimationComponent::Draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (currentAnimation && texture)
    {
        states.texture = texture;
        states.transform *= getTransform();

        if(flipped)
            states.transform.scale(-1.f, 1.f);

        target.draw(vertices, 4, sf::Quads, states);
    }
}
