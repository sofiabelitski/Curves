#ifndef _CURVE_HPP_
#define _CURVE_HPP_

#include "point.hpp"
#include "vector.hpp"


class Curve
{
    public:
        virtual Point get_point(double a_t) = 0;
        virtual Vector get_derivative(double a_t) = 0;

};


#endif /* _CURVE_HPP_ */