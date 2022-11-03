#include "Snake.h"
#include "Constants.h"
namespace snakegame
{

    Part::Part(sf::Vector2f const& position, bool isHead)
        : m_position(position), m_velocity({0,0}), m_size(constants::SPRITES_WIDTH, constants::SPRITES_HEIGHT), m_isHead(isHead)
    {
    }

    static sf::Vector2f rotate_point(float centerX, float centerY, float angle, sf::Vector2f toTranslate)
    {
        float s = sin(angle);
        float c = cos(angle);

        sf::Vector2f point = toTranslate;
        // translate point back to origin:
        point.x -= centerX;
        point.y -= centerY;

        // rotate point
        float xnew = point.x * c - point.y * s;
        float ynew = point.x * s + point.y * c;

        // translate point back:
        point.x = xnew + centerX;
        point.y = ynew + centerY;
        return {point.x, point.y};
    }

    void Part::getVetices(std::vector<sf::Vertex>& vertices)
    {
        int spritePosition = constants::BODY_SPRITE_POSITION;
        if (m_isHead)
        {
            spritePosition = constants::HEAD_SPRITE_POSITION;
        }
        vertices.push_back(sf::Vertex(m_position, sf::Color::White, sf::Vector2f(0, constants::SPRITES_HEIGHT * spritePosition)));
        vertices.push_back(sf::Vertex(m_position + sf::Vector2f(0, m_size.y), sf::Color::White, sf::Vector2f(0, constants::SPRITES_HEIGHT * (spritePosition + 1))));
        vertices.push_back(sf::Vertex(m_position + m_size, sf::Color::White, sf::Vector2f(constants::SPRITES_WIDTH, constants::SPRITES_HEIGHT * (spritePosition + 1))));
        vertices.push_back(sf::Vertex(m_position + sf::Vector2f(m_size.x, 0) , sf::Color::White, sf::Vector2f(constants::SPRITES_WIDTH, constants::SPRITES_HEIGHT * spritePosition)));
    }

    bool Part::intersects(sf::Vector2f const& origin, sf::Vector2f const& size) const
    {
        sf::Vector2f l1 = m_position;
        sf::Vector2f r1 = l1 + m_size;

        sf::Vector2f l2 = origin;
        sf::Vector2f r2 = l2 + size;

        // if rectangle has area 0, no overlap
        if (l1.x == r1.x || l1.y == r1.y || r2.x == l2.x || l2.y == r2.y)
            return false;

        // If one rectangle is on left side of other
        if (r1.x < l2.x || r2.x < l1.x)
            return false;

        // If one rectangle is above other
        if (r1.y < l2.y || r2.y < l1.y)
            return false;

        return true;
    }

    bool Part::intersects(Part const& other) const
    {
        return Part::intersects(other.m_position, other.m_size);
    }
} //namespace