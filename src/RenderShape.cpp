#include <SFML/Graphics.hpp>

#include "RenderShape.h"

namespace snakegame
{
    RenderShape::RenderShape(std::string dir) : RectangleShape()
    {
        m_texture.loadFromFile(dir);
        m_texture.setRepeated(true);
        this->setTexture(&m_texture);
    }
    bool RenderShape::intersects(RenderShape const& other) const
	{
        bool overlaps = true;

        sf::Vector2f l1 = this->getPosition();
        sf::Vector2f r1 = l1 + this->getSize();
        
        sf::Vector2f l2 = other.getPosition();
        sf::Vector2f r2 = l2 + other.getSize();

        // if rectangle has area 0, no overlap
        if (l1.x == r1.x || l1.y == r1.y || r2.x == l2.x || l2.y == r2.y)
            overlaps = false;

        // If one rectangle is on left side of other
        if (r1.x < l2.x || r2.x < l1.x)
            overlaps = false;

        // If one rectangle is above other
        if (r1.y < l2.y || r2.y < l1.y)
            overlaps = false;
           
        return overlaps;
 
	}

} //namespace

