#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(const sf::Texture& texture, RenderLayers layer, bool isRepeated)
	: sprite{ texture }, renderLayer{layer}, repeated {isRepeated}
{
}
