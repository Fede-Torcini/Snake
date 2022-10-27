#pragma once


namespace snakegame
{
class Part
{
public:
    sf::Vector2f m_velocity;
    sf::Vector2f m_position;
    sf::Vector2f m_size;
    bool m_isHead;
    
    Part(sf::Vector2f const& position, bool isHead = false);
    void getVetices(std::vector<sf::Vertex>& vertices);
    bool intersects(sf::Vector2f const& origin, sf::Vector2f const& size) const;
    bool Part::intersects(Part const& other) const;
};
}//namespace

