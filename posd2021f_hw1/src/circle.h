#include "shape.h"
#include <cmath>
class Circle : public Shape
{
public:
    Circle(double radius) : _radius(radius)
    {
        if (_radius <= 0)
        {
            throw "no circle";
        }
    }

    double area() const { return M_PI * _radius * _radius; }

    double perimeter() const { return 2 * M_PI * _radius; }

    std::string info() const
    {
        double _r = round(_radius * 100);
        _r = _r / 100;
        std::stringstream Cirstring;
        Cirstring << "Circle ("
                  << std::fixed << std::setprecision(2) << _r
                  << ")";
        return Cirstring.str();
    }

private:
    double _radius;
};
