#include <iostream>
#include <cmath>

#include "vector.hpp"


void test_get_coordinate()
{
    double x = 1.0;
    double y = 2.0;
    double z = 3.0;

    Vector v{Point{x, y, z}};

    Point p = v.get_coordinate();

    if(p.get_x() == x && p.get_y() == y && p.get_z() == z)
    {
        std::cout << "Test get coordinate pass" << std::endl;
    }
    else
    {
        std::cout << "Test get coordinate fail" << std::endl;
    }
}


void test_get_length()
{
    double x = 1.0;
    double y = 2.0;
    double z = 3.0;

    Vector v{Point{x, y, z}};

    if(v.get_length() == std::sqrt(pow(x, 2) + pow(y, 2)  + pow(z, 2)))
    {
        std::cout << "Test get length pass" << std::endl;
    }
    else
    {
        std::cout << "Test get length fail" << std::endl;
    }
    
}



int main()
{
    test_get_coordinate();
    test_get_length();
}