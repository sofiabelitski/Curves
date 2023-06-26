#include <vector>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <memory>
#include <stdexcept>
#include <typeinfo>
#include <algorithm>

#include "curves_generator.hpp"
#include "ellipse.hpp"
#include "circle.hpp"
#include "helix.hpp"

bool compare_circles(const std::unique_ptr<Circle>& a_first, const std::unique_ptr<Circle>& a_second)
{
    return a_first->get_radius() < a_second->get_radius();
}


void fill_curves_vector(std::vector<std::unique_ptr<Curve>>& a_curves)
{
    CurvesGenerator generator;

    int size = 10;

    for(int i = 0; i < size; ++i)
    {
        a_curves.push_back(generator.generate_curve());

    }
}

void print_curves_vector(std::vector<std::unique_ptr<Curve>>& a_curves)
{
    for(const auto& el: a_curves)
    {
        std::cout << el->get_point(M_PI/4) << '\t';
        std::cout << el->get_derivative(M_PI/4) << std::endl;
        std::cout << std::endl;

    }
}

void fill_circles_vector(std::vector<std::unique_ptr<Curve>>& a_curves, std::vector<std::unique_ptr<Circle>>& a_circles)
{
     for(const auto& el: a_curves)
    {
        try{
            Circle c = dynamic_cast<Circle&>(*el);  
            a_circles.push_back(std::make_unique<Circle>(c));
        }
        catch(...)
        {
            
        }
    }
}

void print_radii(std::vector<std::unique_ptr<Circle>>& a_circles)
{
    for(const auto& el: a_circles)
    {
        std::cout << el->get_radius() << " ";  
        
    }
    std::cout << std::endl;
}

double count_radii_sum(std::vector<std::unique_ptr<Circle>>& a_circles)
{
    double sum_of_radii = 0;

    for(const auto& el: a_circles)
    {
        sum_of_radii += el->get_radius();  
        
    }

    return sum_of_radii;
}

int main()
{
    
    std::vector<std::unique_ptr<Curve>> curves;

    fill_curves_vector(curves);

    print_curves_vector(curves);

    std::vector<std::unique_ptr<Circle>> circles;

    fill_circles_vector(curves, circles);


    std::cout << "Radii before sort: ";

    print_radii(circles);

    sort(circles.begin(), circles.end(), compare_circles);

    
    std::cout << "Radii after sort:  ";
    
    print_radii(circles);

    std::cout << "Sum of radiuses:   " << count_radii_sum(circles) << std::endl;  


}