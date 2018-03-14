#include <iostream>
#include "SFMLWindow.h"

SFMLWindow::SFMLWindow()
{
	create(sf::VideoMode(800, 600), "");
}

SFMLWindow::SFMLWindow(sf::Vector2i size, sf::String title, sf::Color bgColor)
{
	create(sf::VideoMode(size.x, size.y), title);
	backgroundColor = bgColor;
}

void SFMLWindow::Draw(const sf::Drawable &drawable)
{
	draw(drawable);
}

void SFMLWindow::Clear()
{
	clear(backgroundColor);
}

void SFMLWindow::Display()
{
	display();
}