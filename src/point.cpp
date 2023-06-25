#include "point.hpp"

#include <iomanip>

Point::Point(double a_x, double a_y, double a_z) noexcept
: m_x(a_x)
, m_y(a_y)
, m_z(a_z)
{

}

Point::Point(const Point& a_other) noexcept
: m_x(a_other.m_x)
, m_y(a_other.m_y)
, m_z(a_other.m_z)
{

}

Point::~Point()
{

}


Point& Point::add_delta(double a_x_delta, double a_y_delta, double a_z_delta)
{
    m_x += a_x_delta;
    m_y += a_y_delta;
    m_z += a_z_delta;

    return *this;
}


Point Point::operator+(const Point& a_other)
{
    m_x += a_other.m_x;
    m_y += a_other.m_y;
    m_z += a_other.m_z;

    return Point(m_x, m_y, m_z);
}

Point Point::operator-(const Point& a_other)
{
    m_x -= a_other.m_x;
    m_y -= a_other.m_y;
    m_z -= a_other.m_z;

    return Point(m_x, m_y, m_z);
}

void Point::operator=(const Point& a_other)
{
    m_x = a_other.m_x;
    m_y = a_other.m_y;
    m_z = a_other.m_z;

}

void Point::operator*=(double a_delta)
{
    m_x *= a_delta;
    m_y *= a_delta;
    m_z *= a_delta;

}

bool Point::operator==(const Point& a_other)
{
    return ( m_x == a_other.m_x && m_y == a_other.m_y && m_z == a_other.m_z );
}


bool Point::operator!=(const Point& a_other)
{
    return !( (*this) == a_other);
}

std::ostream& operator<<(std::ostream& a_out, const Point& a_point)
{
    a_out << "Point(" << std::setprecision(2) << a_point.m_x << ", " << a_point.m_y << ", " << a_point.m_z << ")";
    return a_out;
}