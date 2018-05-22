#pragma once

#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>

class Animation
{
public:
    void addFrame(sf::IntRect rect);
    const sf::Texture* getSpriteSheet() const;
    std::size_t getSize() const;
    const sf::IntRect& getFrame(std::size_t n) const;

    bool loadFromFile(const std::string& filename);

private:
    std::vector<sf::IntRect> m_frames;
    sf::Texture m_texture;
};
