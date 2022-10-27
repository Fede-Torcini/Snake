#pragma once

#include <SFML/Graphics.hpp>

#include "Part.h"
#include "RenderShape.h"

namespace snakegame
{
class Snake
{
public:
    Snake();
    void move();
    void setVelocity(sf::Vector2f const& movement);
    int partCount() const;
    void grow();
    bool intersects(RenderShape const& other) const;
    bool alive() const;
    sf::Vertex* draw();
    sf::Texture* getTexture();

private:

    float m_speed;
    
    std::vector<Part> m_body;
    sf::Texture m_texture;
    std::vector<sf::Vertex> m_vertices;
};
}//namespace

