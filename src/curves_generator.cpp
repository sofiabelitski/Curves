#include <ctime>

#include "curves_generator.hpp"


static int generate_random(int min, int max);
static std::unique_ptr<Curve> generate_ellipse();
static std::unique_ptr<Curve> generate_circle();
static std::unique_ptr<Curve> generate_helix();

CurvesGenerator::CurvesGenerator()
{
    srand(static_cast<unsigned int>(time(0)));
    rand(); 
}

CurvesGenerator::~CurvesGenerator()
{

}

std::unique_ptr<Curve> CurvesGenerator::generate_curve()
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

static int generate_random(int min, int max) 
{
    static const double fraction =  1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
            
    return static_cast<int>(rand() * fraction *(max - min + 1) + min);
}

static std::unique_ptr<Curve> generate_ellipse()
{
    int x = generate_random(-10, 10);
    int y = generate_random(0, 10);

    double first_radius = generate_random(1, 10);
    double second_radius = generate_random(1, 10);
    
    return std::make_unique<Ellipse>(Ellipse(Point(x, y, 0.0), first_radius, second_radius));
               
}

static std::unique_ptr<Curve> generate_circle()
{
    int x = generate_random(-10, 10);
    int y = generate_random(0, 10);
    
    double radius = generate_random(1, 10);
    
    return std::make_unique<Circle>(Circle(Point(x, y, 0.0), radius));
               
}

static std::unique_ptr<Curve> generate_helix()
{
    double radius = generate_random(1, 10);
    double step = generate_random(1, 10);
    
    return std::make_unique<Helix>(Helix(radius, step));
}