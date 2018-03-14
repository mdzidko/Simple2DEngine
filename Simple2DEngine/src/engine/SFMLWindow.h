#pragma once

#include <memory>
#include "SFML/Graphics/RenderWindow.hpp"

class SFMLWindow : private sf::RenderWindow
{
public:
	SFMLWindow();
	SFMLWindow(sf::Vector2i size, sf::String title, sf::Color bgColor);

	virtual void Draw(const sf::Drawable &drawable);
	virtual void Clear();
	virtual void Display();

private:
	sf::Color backgroundColor;
};

typedef std::shared_ptr<SFMLWindow> SFMLWindowPtr;

