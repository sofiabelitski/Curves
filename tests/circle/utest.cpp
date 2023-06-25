#include <iostream>
#include <stdexcept>
#include <cmath>

#include "circle.hpp"

void test_constructor_bad()
{
    double negative_num = -1.0;

    try
    {
        Circle c{Point(1.0, 1.0), negative_num};
    }
    catch(std::runtime_error& err)
    {
        std::cout << "Test constructor bad pass" << std::endl;
        return;
    }

    std::cout << "Test constructor bad fail" << std::endl;
    
}

void test_constructor_good()
{
    double positive_num = 3.0;
    
    try
    {
        Circle e{Point(1.0, 1.0), positive_num};
    }
    catch(std::runtime_error& err)
    {
        std::cout << "Test constructor good fail" << std::endl;
        return;
    }

    std::cout << "Test constructor good pass" << std::endl;
    
}

void test_get_center()
{
    double radius = 5;

    Point p{1.4, 6.8};

    Circle c{p, radius};

    if(p == c.get_center())
    {
        std::cout << "Test get center pass" << std::endl;
    }
    else{
        std::cout << "Test get center fail" << std::endl;
    }

}

void test_get_radius()
{
    double radius = 5;

    Circle c{Point(1.0, 1.0), radius};

    if(radius == c.get_radius() )
    {
        std::cout << "Test get radius pass" << std::endl;
    }
    else{
        std::cout << "Test get radius fail" << std::endl;
    }

}

void test_get_point()
{
    double radius = 3;
    
    Circle c{Point(1.0, 1.0), radius};

    Point p{radius*cos(M_PI), radius*sin(M_PI)};
    
    if(p == c.get_point(M_PI))
    {
        std::cout << "Test get point pass" << std::endl;
    }
    else{
        std::cout << "Test get point fail" << std::endl;
    }
  
}

void test_get_derivative()
{
    double radius = 5.8;

    Circle c{Point(1.0, 1.0), radius};

    Point p{radius*cos(M_PI), radius*sin(M_PI)};
    
    if(p == c.get_derivative(M_PI).get_coordinate())
    {
        std::cout << "Test get derivative pass" << std::endl;
    }
    else{
        std::cout << "Test get derivative fail" << std::endl;
    }
  
}

int main()
{
    test_constructor_bad();
    test_constructor_good();
    test_get_center();
    test_get_radius();
    test_get_point();
    test_get_derivative();
}