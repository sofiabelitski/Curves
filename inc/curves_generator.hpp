#include <memory>

#include "ellipse.hpp"
#include "circle.hpp"
#include "helix.hpp"



class CurvesGenerator
{
    private:
        enum Curve_id
        {
            ELLIPS,
            CIRCLE,
            HELIX,
            MAX_ID
        };
    public:
        CurvesGenerator();
        virtual ~CurvesGenerator();
        std::unique_ptr<Curve> generate_curve();

};