#include "SFMLWindowFactory.h"

SFMLWindowFactory::SFMLWindowFactory(int width, int height, std::string title, sf::Color bgColor) :
windowSize{ width, height }, windowTitle{ title }, backgroundColor{ bgColor }
{
}

SFMLWindowPtr SFMLWindowFactory::Create()
{
	std::shared_ptr<SFMLWindow> window;
	window = std::make_shared<SFMLWindow>(windowSize, windowTitle, backgroundColor);

	return window;
}
