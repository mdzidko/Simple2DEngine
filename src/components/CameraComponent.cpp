#include "CameraComponent.h"

CameraComponent::CameraComponent(sf::Vector2f offset)
{
    this->offset = offset;
}

sf::Vector2f CameraComponent::GetOffset() {
    return offset;
}
