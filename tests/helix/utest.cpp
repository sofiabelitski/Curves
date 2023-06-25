#include <iostream>
#include <stdexcept>
#include <cmath>

#include "helix.hpp"


void test_constructor_bad()
{
    double radius = 0.0;
    double step = -1.0;
    try
    {
        Helix h{radius, step};
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
    double radius = 1.0;
    double step = 1.0;
    try
    {
        Helix h{radius, step};
    }
    catch(std::runtime_error& err)
    {
        std::cout << "Test constructor good fail" << std::endl;
        return;
    }
    std::cout << "Test constructor good pass" << std::endl;
    
}

void test_get_radius()
{
    double radius = 1.0;
    double step = 1.0;
    
    Helix h{radius, step};
    
    if(h.get_radius() == radius)
    {
        std::cout << "Test get radius pass" << std::endl;
        
    }
    else{
        std::cout << "Test get radius fail" << std::endl;
    }
    
}

void test_get_step()
{
    double radius = 1.0;
    double step = 1.0;
    
    Helix h{radius, step};
    
    if(h.get_step() == step)
    {
        std::cout << "Test get step pass" << std::endl;
        
    }
    else{
        std::cout << "Test get step fail" << std::endl;
    }
    
}

void test_get_point()
{
    double radius = 3.0;
    double step = 7.0;
    
    Helix h{radius, step};

    Point p{radius*cos(M_PI), radius*sin(M_PI), step*M_PI};
    
    if(p == h.get_point(M_PI))
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
    double step = 7.0;

    Helix h{radius, step};

    Point p{radius*cos(M_PI), radius*sin(M_PI), step*M_PI};
    
    if(p == h.get_derivative(M_PI).get_coordinate())
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
    test_get_radius();
    test_get_step();
    test_get_point();
    test_get_derivative();
}