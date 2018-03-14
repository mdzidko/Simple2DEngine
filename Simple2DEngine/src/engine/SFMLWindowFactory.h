#pragma once

#include "SFMLWindow.h"

class SFMLWindowFactory
{
public:
	SFMLWindowFactory(int width, int height, std::string title, sf::Color bgColor);

	SFMLWindowPtr Create();

private:
	sf::Vector2i windowSize;
	sf::String windowTitle;
	sf::Color backgroundColor;
};

typedef std::unique_ptr<SFMLWindowFactory> SFMLWindowFactoryPtr;