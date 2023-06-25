#include <cmath>
#include <stdexcept>

#include "point.hpp"
#include "vector.hpp"
#include "curve.hpp"
#include "circle.hpp"


Circle::Circle(Point a_center, double a_radius)
: Ellipse(a_center, a_radius, a_radius)
{

}

Circle::~Circle()
{

}

double Circle::get_radius() const
{
    return Ellipse::get_first_radius();
}


