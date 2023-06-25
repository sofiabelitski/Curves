#include <stdexcept>
#include <cmath>

#include "helix.hpp"

static bool check_parameter(double a_p);

Helix::Helix(double a_radius, double a_step)
: m_radius(a_radius)
, m_step(a_step)
{
   if(a_radius <= 0 || m_step < 0)
   {
        throw std::runtime_error("Radius <= 0 or step < 0");
   } 
}

Helix::~Helix()
{

}

double Helix::get_radius() const
{
    return m_radius;
}

double Helix::get_step() const
{
    return m_step;
}

Point Helix::get_point(double a_t)
{
    if(!check_parameter(a_t))
    {
        throw std::runtime_error("Parameter t < 0 or > 2PI");
    }
    
    return Point(m_radius*cos(a_t), m_radius*sin(a_t), m_step*a_t);
}

Vector Helix::get_derivative(double a_t)
{
    return Vector(get_point(a_t));
}

static bool check_parameter(double a_p)
{
    return (a_p > 0 && a_p < 2*M_PI);
}