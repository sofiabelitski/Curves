#ifndef _CIRCLE_HPP_
#define _CIRCLE_HPP_

#include <memory>

#include "point.hpp"
#include "vector.hpp"
#include "curve.hpp"
#include "ellipse.hpp"

class Circle: public Ellipse
{
    private:
        Point m_center;
        double m_radius;
    public:
        Circle(Point a_center, double a_radius);
        virtual ~Circle();
        double get_radius() const;
    
};


#endif /* _CIRCLE_HPP_ */