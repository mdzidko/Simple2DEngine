#include "PositionComponent.h"

PositionComponent::PositionComponent(sf::Vector2f& pos)
        : position{ pos }
{
}

PositionComponent::PositionComponent()
{
}

PositionComponent::PositionComponent(float x, float y)
    : position{ x, y }
{
}

const sf::Vector2f& PositionComponent::GetPosition() const
{
    return position;
}

void PositionComponent::SetPosition(const sf::Vector2f& pos)
{
    position = pos;
}

