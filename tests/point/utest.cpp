#include <iostream>

#include "point.hpp"

void test_default_arguments()
{
    Point p;
    
    if(p.get_x() == 0.0 && p.get_y() == 0.0 && p.get_z() == 0.0)
    {
        std::cout << "Test default arguments pass" << std::endl;
    }
    else
    {
        std::cout << "Test default arguments fail" << std::endl;
    }

}

void test_get()
{
    double x = 1.0;
    double y = 2.0;
    double z = 3.0;
    Point p{x, y, z};
    
    if(p.get_x() == x && p.get_y() == y && p.get_z() == z)
    {
        std::cout << "Test get pass" << std::endl;
    }
    else
    {
        std::cout << "Test get fail" << std::endl;
    }

}

void test_set()
{
    double x = 1.0;
    double y = 2.0;
    double z = 3.0;
    Point p;
    
    p.set_x(x);
    p.set_y(y);
    p.set_z(z);

    if(p.get_x() == x && p.get_y() == y && p.get_z() == z)
    {
        std::cout << "Test set pass" << std::endl;
    }
    else
    {
        std::cout << "Test set fail" << std::endl;
    }
}

void test_add_delta()
{
    double x = 1.0;
    double y = 2.0;
    double z = 3.0;
    double delta = 1.0;
    Point p{x, y, z};
    
    p.add_delta(delta, delta, delta);

    if(p.get_x() == (x + delta) && p.get_y() == (y + delta) && p.get_z() == (z + delta))
    {
        std::cout << "Test add delta pass" << std::endl;
    }
    else
    {
        std::cout << "Test add delta fail" << std::endl;
    }
}

void test_operator_plus()
{
    double x = 1.0;
    double y = 2.0;
    double z = 3.0;

    Point p1{x, y, z};
    Point p2{x, y, z};

    Point sum = p1 + p2;

    if(sum.get_x() == (x + x) && sum.get_y() == (y + y) && sum.get_z() == (z + z))
    {
        std::cout << "Test operator+ pass" << std::endl;
    }
    else
    {
        std::cout << "Test operator+ fail" << std::endl;
    }
}

void test_operator_minus()
{
    double x = 1.0;
    double y = 2.0;
    double z = 3.0;

    Point p1{x, y, z};
    Point p2{x, y, z};

    Point difference = p1 - p2;

    if(difference.get_x() == (x - x) && difference.get_y() == (y - y) && difference.get_z() == (z - z))
    {
        std::cout << "Test operator- pass" << std::endl;
    }
    else
    {
        std::cout << "Test operator- fail" << std::endl;
    }
}

void test_operator_assignment()
{
    double x = 1.0;
    double y = 2.0;
    double z = 3.0;

    Point p1{x, y, z};
    Point p2;

    p2 = p1;

    if(p2.get_x() == x && p2.get_y() == y && p2.get_z() == z)
    {
        std::cout << "Test operator= pass" << std::endl;
    }
    else
    {
        std::cout << "Test operator= fail" << std::endl;
    }
}

void test_operator_composition()
{
    double x = 1.0;
    double y = 2.0;
    double z = 3.0;

    Point p{x, y, z};
    
    double delta = 3.0;

    p *= delta;

    if(p.get_x() == x*delta && p.get_y() == y*delta && p.get_z() == z*delta)
    {
        std::cout << "Test operator*= pass" << std::endl;
    }
    else
    {
        std::cout << "Test operator*= fail" << std::endl;
    }
}

void test_operator_equal()
{
    double x = 1.0;
    double y = 2.0;
    double z = 3.0;

    double x_ = 4.0;
    double y_ = 5.0;
    double z_ = 6.0;

    Point p1{x, y, z};
    Point p2{x, y, z};
    Point p3{x_, y_, z_};
    

    if( p1 == p2 && !(p1 == p3) && !(p2 == p3))
    {
        std::cout << "Test operator== pass" << std::endl;
    }
    else
    {
        std::cout << "Test operator== fail" << std::endl;
    }
}

void test_operator_not_equal()
{
    double x = 1.0;
    double y = 2.0;
    double z = 3.0;

    double x_ = 4.0;
    double y_ = 5.0;
    double z_ = 6.0;

    Point p1{x, y, z};
    Point p2{x, y, z};
    Point p3{x_, y_, z_};
    

    if( !(p1 != p2) && (p1 != p3) && (p2 != p3))
    {
        std::cout << "Test operator!= pass" << std::endl;
    }
    else
    {
        std::cout << "Test operator!= fail" << std::endl;
    }
}

int main()
{
    test_default_arguments();
    test_get();
    test_set();
    test_add_delta();
    test_operator_plus();
    test_operator_minus();
    test_operator_assignment();
    test_operator_composition();
    test_operator_equal();
    test_operator_not_equal();
}