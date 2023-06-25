#include <cmath>

#include "vector.hpp"


Vector::Vector(Point a_direction_point, Point a_start_point) noexcept
{
    m_coordinate.set_x(a_direction_point.get_x() - a_start_point.get_x());
    m_coordinate.set_y(a_direction_point.get_y() - a_start_point.get_y());
    m_coordinate.set_z(a_direction_point.get_y() - a_start_point.get_y());
}

Vector::Vector(const Point& a_coordinate) noexcept
: m_coordinate(a_coordinate)
{

}

Vector::Vector(const Vector& a_other) noexcept
: m_coordinate(a_other.m_coordinate)
{

}

Vector::~Vector() 
{

}     

Point Vector::get_coordinate() const 
{ 
    return m_coordinate;
}

double Vector::get_length() const 
{ 
    double x_length = pow(m_coordinate.get_x(), 2);
    double y_length = pow(m_coordinate.get_y(), 2);
    double z_length = pow(m_coordinate.get_z(), 2);

    return std::sqrt( x_length + y_length + z_length);
}

std::ostream& operator<<(std::ostream& a_out, const Vector& a_vector)
{
    a_out << "Vector(" << a_vector.m_coordinate.get_x() << ", " << a_vector.m_coordinate.get_y() << ", " << a_vector.m_coordinate.get_z() << ")";
    return a_out;
}