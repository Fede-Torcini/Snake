#pragma once
#include <Vector2.h>

namespace snakegame
{
class Snake
{
public:
    Vector2 getPosition() const;
    void move();
    void setVelocity(Vector2 const& movement);
private:
    Vector2 m_position{ 0,0 };
    Vector2 m_velocity{ 0,0 };
};
}//namespace

