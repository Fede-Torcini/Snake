#pragma once
#include <SFML/Graphics.hpp>

namespace snakegame
{
class RenderShape : public sf::RectangleShape
{
public:
    RenderShape(std::string dir);
    bool intersects(RenderShape const& other) const;
private:
    sf::Texture m_texture;
};
} //namespace

