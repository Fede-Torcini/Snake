#include "Vector2.h"

namespace snakegame
{
Vector2::Vector2(double x, double y)
	: m_x(x), m_y(y)
{}
double Vector2::x() const { return m_x; }
double Vector2::y() const { return m_y; }

Vector2& Vector2::operator+=(const Vector2& other)
{
	m_x += other.x();
	m_y += other.y();
	return *this;
	}
} //namespace