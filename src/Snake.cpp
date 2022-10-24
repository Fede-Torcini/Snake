#include "Snake.h"

namespace snakegame
{
    Vector2 Snake::getPosition() const
    {
        return m_position;
    }
    void Snake::move()
    {
        m_position += m_velocity;
    }
    void Snake::setVelocity(Vector2 const& velocity)
    {
        m_velocity = velocity;
    }
} //namespace