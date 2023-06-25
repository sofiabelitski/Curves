#include <stdexcept>
#include <cmath>

#include "ellipse.hpp"

static bool check_parameter(double a_p);

Ellipse::Ellipse(Point a_center, double a_first_radius, double a_second_radius)
: m_center(a_center)
, m_first_radius(a_first_radius)
, m_second_radius(a_second_radius)
{
    if(a_first_radius <= 0 || a_second_radius <= 0)
    { 
        throw std::runtime_error("Radius <= 0");
    }
}

Ellipse::~Ellipse()
{

}

Point& Ellipse::get_center() 
{
    return m_center;
}

double Ellipse::get_first_radius() const
{
    return m_first_radius;
}

double Ellipse::get_second_radius() const
{
    return m_second_radius;
}

Point Ellipse::get_point(double a_t)
{
    if(!check_parameter(a_t))
    {
        throw std::runtime_error("Parameter t < 0 or > 2PI");
    }

    return Point(m_first_radius*cos(a_t), m_second_radius*sin(a_t));
}

Vector Ellipse::get_derivative(double a_t)
{
    return Vector(get_point(a_t));
}

static bool check_parameter(double a_p)
{
    return (a_p > 0 && a_p < 2*M_PI);
}