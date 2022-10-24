#pragma once
namespace snakegame
{
class Vector2
{
public:
    Vector2() = delete;
    Vector2(double x, double y);
    double x() const;
    double y() const;

    Vector2& operator+=(const Vector2& other);

private:
    double m_x, m_y;
};
}//namespace

