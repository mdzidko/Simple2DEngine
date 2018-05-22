#include <fstream>
#include <c++/iostream>
#include "Animation.h"
#include <../utils/json/json.hpp>

using json = nlohmann::json;

void Animation::addFrame(sf::IntRect rect)
{
    m_frames.push_back(rect);
}

const sf::Texture* Animation::getSpriteSheet() const
{
    return &m_texture;
}

std::size_t Animation::getSize() const
{
    return m_frames.size();
}

const sf::IntRect& Animation::getFrame(std::size_t n) const
{
    return m_frames[n];
}

bool Animation::loadFromFile(const std::string &filename)
{
    try {
        std::ifstream animationFile(filename);

        json jsonAnimation;
        animationFile >> jsonAnimation;

        std::string textureFile = jsonAnimation["texture"];

        auto frames = jsonAnimation.at("frames");

        for (auto f : frames)
            addFrame({f[0], f[1], f[2], f[3]});

        animationFile.close();

        m_texture.loadFromFile(textureFile);
    }
    catch(...)
    {
        return false;
    }

    return true;
}
