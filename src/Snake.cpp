#include "Snake.h"
#include "Constants.h"

namespace snakegame
{

    Snake::Snake()
        : m_speed(constants::SNAKE_SPEED)
    {
        m_body.push_back(Part({ 0,0 }, true));

        m_texture.loadFromFile(constants::SNAKE_TEXTURE_DIRECTORY);
        m_texture.setRepeated(true);

    }
    
    void Snake::move()
    {        
        for (Part& part : m_body)
        {
            part.m_position = part.m_position + (part.m_velocity * m_speed);   
        }
        setVelocity(m_body[0].m_velocity);
    }
    
    void Snake::setVelocity(sf::Vector2f const& velocity)
    {
        sf::Vector2f target;

        for (unsigned int i{0}; i < m_body.size(); i++)
        {
            if (i != 0)
            {
                float SlopeX = target.x - m_body[i].m_position.x;
                float SlopeY = target.y - m_body[i].m_position.y;
                float result = sqrt(SlopeY * SlopeY + SlopeX * SlopeX);
                m_body[i].m_velocity.y = result != 0 ? (SlopeY / result) : 0;
                m_body[i].m_velocity.x = result != 0 ? (SlopeX / result) : 0;
            }
            else
                m_body[0].m_velocity = velocity;

            target = m_body[i].m_position;
        }

    }

    /*
     * Returns Vertexptr to an array of all snake Vertexes 
     */
    sf::Vertex* Snake::draw()
    {
        m_vertices.clear();
        
        for (int i = m_body.size() - 1; i >= 0; i--)
        {
            m_body[i].getVetices(m_vertices);
        }

        return &m_vertices[0];
    }

    /*
     * Given a render shape,
     * returns if the snake collides with it  
     */
    bool Snake::intersects(RenderShape const& other) const
    {
        for (auto& part : m_body)
        {
            if (part.intersects(other.getPosition(), other.getSize()))
                return true;
        }
        return false;
    }

    /*
     * returns snake size
     */
    int Snake::partCount() const
    {
       return m_body.size();
    }

    sf::Texture* Snake::getTexture()
    {
        return &m_texture;
    }

    /*
     * Pushes new part to the body at the tail position 
     */
    void Snake::grow() 
    {   
        // new part gets initialized at the left of the last body part
        m_body.push_back(Part(m_body[m_body.size() - 1].m_position - sf::Vector2f{constants::SPRITES_WIDTH, 0}));
        m_speed += .1f;
    }

    /*
     * Returns if snake is getting out of bounds 
     */
    bool Snake::alive() const
    {
        return (m_body[0].m_position.x + constants::SPRITES_WIDTH/2) >= 0 
            && (m_body[0].m_position.x + constants::SPRITES_WIDTH/2) <= constants::WINDOW_WIDTH
            && (m_body[0].m_position.y + constants::SPRITES_HEIGHT/2) >= 0
            && (m_body[0].m_position.y + constants::SPRITES_HEIGHT/2) <= constants::WINDOW_HEIGHT;
    }

} //namespace