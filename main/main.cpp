#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <functional>
#include <memory>
#include <stdexcept>
#include <typeinfo>
#include <algorithm>

#include "ellipse.hpp"
#include "circle.hpp"
#include "helix.hpp"

int generate_random(int min, int max) 
{
    static const double fraction =  1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
            
    return static_cast<int>(rand() * fraction *(max - min + 1) + min);
}

enum Curve_id
{
    ELLIPS,
    CIRCLE,
    HELIX,
    MAX_ID
};

std::unique_ptr<Curve> generate_ellipse()
{
    int x = generate_random(-10, 10);
    int y = generate_random(0, 10);

    double first_radius = generate_random(1, 10);
    double second_radius = generate_random(1, 10);
    
    return std::make_unique<Ellipse>(Ellipse(Point(x, y, 0.0), first_radius, second_radius));
               
}

std::unique_ptr<Curve> generate_circle()
{
    int x = generate_random(-10, 10);
    int y = generate_random(0, 10);
    
    double radius = generate_random(1, 10);
    
    return std::make_unique<Circle>(Circle(Point(x, y, 0.0), radius));
               
}

std::unique_ptr<Curve> generate_helix()
{
    double radius = generate_random(1, 10);
    double step = generate_random(1, 10);
    
    return std::make_unique<Helix>(Helix(radius, step));
}

std::unique_ptr<Curve> generate_curve()
{

    int num = generate_random(0, MAX_ID - 1);
    switch(num)
    {
        case ELLIPS:
            return generate_ellipse();
        case CIRCLE:
            return generate_circle();
        case HELIX:
            return generate_helix();
        default:
            throw std::runtime_error("Unknown curve type");
    }

}

bool compare_circles(const std::unique_ptr<Circle>& a_first, const std::unique_ptr<Circle>& a_second)
{
    return a_first->get_radius() < a_second->get_radius();
}


int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand(); 
    
    std::vector<std::unique_ptr<Curve>> curves;

    int size = 10;

    for(int i = 0; i < size; ++i)
    {
        curves.push_back(generate_curve());

    }

    for(const auto& el: curves)
    {
        std::cout << el->get_point(M_PI/4) << '\t';
        std::cout << el->get_derivative(M_PI/4) << std::endl;
        std::cout << std::endl;

    }

    std::vector<std::unique_ptr<Circle>> circles;

    for(const auto& el: curves)
    {
        try{
            Circle c = dynamic_cast<Circle&>(*el);  
            circles.push_back(std::make_unique<Circle>(c));
        }
        catch(...)
        {
            
        }
    }

    for(const auto& el: circles)
    {
        std::cout << "Radius before sort = " << el->get_radius() << std::endl;  
        
    }

    std::cout << std::endl;

    sort(circles.begin(), circles.end(), compare_circles);

    for(const auto& el: circles)
    {
        std::cout << "Radius after sort = " << el->get_radius() << std::endl;  
        
    }

    std::cout << std::endl;

    double sum_of_radii = 0;

    for(const auto& el: circles)
    {
        sum_of_radii += el->get_radius();  
        
    }

    std::cout << "Sum of radiuses = " << sum_of_radii << std::endl;  


}