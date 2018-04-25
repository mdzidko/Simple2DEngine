#include "MovementComponent.h"

const sf::Vector2f &MovementComponent::GetVelocity() const {
    return velocity;
}

void MovementComponent::SetVelocity(const sf::Vector2f &velocity)
{
    this->velocity = velocity;
}

const sf::Vector2f &MovementComponent::GetAcceleration() const
{
    return acceleration;
}

void MovementComponent::SetAcceleration(const sf::Vector2f &acceleration)
{
    this->acceleration = acceleration;
}
