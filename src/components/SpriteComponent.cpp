#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(const sf::Texture& texture, RenderLayers layer, int sizeX, int sizeY, bool isRepeated)
	: sprite{ texture }, renderLayer{layer}, repeated {isRepeated}
{
	if(sizeX != 0 && sizeY != 0)
		sprite.setTextureRect({0, 0, sizeX, sizeY});
}
