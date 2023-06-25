#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include "point.hpp"

class Vector
{
    private:
        Point m_coordinate;
    public:
        Vector(Point a_direction_point, Point a_start_point) noexcept;
        Vector(const Point& a_coordinate) noexcept;
        Vector(const Vector& a_other) noexcept;
        virtual ~Vector();
        Point get_coordinate() const;
        double get_length() const;
        friend std::ostream& operator<<(std::ostream& a_out, const Vector& a_vector);

};




#endif /* _VECTOR_HPP_ */