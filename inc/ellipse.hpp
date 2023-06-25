#ifndef _ELLIPSE_HPP_
#define _ELLIPSE_HPP_

#include "point.hpp"
#include "vector.hpp"
#include "curve.hpp"

class Ellipse: public Curve
{
    private:
        Point m_center;
        double m_first_radius;
        double m_second_radius;
    public:
        explicit Ellipse(Point a_center, double a_first_radius, double a_second_radius);
        virtual ~Ellipse();
        Point& get_center();
        double get_first_radius() const;
        double get_second_radius() const;
        virtual Point get_point(double a_t) override;
        virtual Vector get_derivative(double a_t) override;
};


#endif /* _ELLIPSE_HPP_ */