#ifndef _HELIX_HPP_
#define _HELIX_HPP_

#include "curve.hpp"
#include "point.hpp"

class Helix: public Curve
{
    private:
        double m_radius;
        double m_step;
    public:
        Helix(double a_radius, double a_step);
        virtual ~Helix();
        double get_radius() const;
        double get_step() const;
        Point get_point(double a_t) override;
        Vector get_derivative(double a_t) override;
        
};

#endif /* _HELIX_HPP_ */