#include <iostream>
#include <stdexcept>
#include <cmath>

#include "ellipse.hpp"

void test_constructor_bad()
{
    double null_num = 0.0;
    double negative_num = -1.0;

    try
    {
        Ellipse e{Point(1.0, 1.0), null_num, negative_num};
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
    double positive_num_2 = 5.0;
    
    try
    {
        Ellipse e{Point(1.0, 1.0), positive_num, positive_num_2};
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
    double first_radius = 3;
    double second_radius = 5;

    Point p{1.4, 6.8};

    Ellipse e{p, first_radius, second_radius};

    if(p == e.get_center())
    {
        std::cout << "Test get center pass" << std::endl;
    }
    else{
        std::cout << "Test get center fail" << std::endl;
    }

}

void test_get_radius()
{
    double first_radius = 3;
    double second_radius = 5;

    Ellipse e{Point(1.0, 1.0), first_radius, second_radius};

    if(first_radius == e.get_first_radius() && second_radius == e.get_second_radius())
    {
        std::cout << "Test get radius pass" << std::endl;
    }
    else{
        std::cout << "Test get radius fail" << std::endl;
    }

}

void test_get_point()
{
    double first_radius = 3;
    double second_radius = 5;

    Ellipse e{Point(1.0, 1.0), first_radius, second_radius};

    Point p{first_radius*cos(M_PI), second_radius*sin(M_PI)};
    
    if(p == e.get_point(M_PI))
    {
        std::cout << "Test get point pass" << std::endl;
    }
    else{
        std::cout << "Test get point fail" << std::endl;
    }
  
}

void test_get_derivative()
{
    double first_radius = 3;
    double second_radius = 5;

    Ellipse e{Point(1.0, 1.0), first_radius, second_radius};

    Point p{first_radius*cos(M_PI), second_radius*sin(M_PI)};
    
    if(p == e.get_derivative(M_PI).get_coordinate())
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