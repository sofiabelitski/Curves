#ifndef _POINT_HPP_
#define _POINT_HPP_

#include <iostream>

class Point
{
    private:
        double m_x;
        double m_y;
        double m_z;
    public:
        Point(double a_x = 0.0, double a_y = 0.0, double a_z = 0.0) noexcept;
        Point(const Point& a_other) noexcept;
        virtual ~Point();

        inline double get_x() const { return m_x; }
        inline double get_y() const { return m_y; }
        inline double get_z() const { return m_z; }

        inline void set_x(double a_x) { m_x = a_x; }
        inline void set_y(double a_y) { m_y = a_y; }
        inline void set_z(double a_z) { m_z = a_z; }


        Point& add_delta(double a_x_delta, double a_y_delta = 0.0, double a_z_delta = 0.0);
        Point operator+(const Point& a_other);
        Point operator-(const Point& a_other);
        void operator*=(double a_delta);
        void operator=(const Point& a_other);
        bool operator==(const Point& a_other);
        bool operator!=(const Point& a_other);

        friend std::ostream& operator<<(std::ostream& a_out, const Point& a_point);

};

#endif /* _POINT_HPP_ */