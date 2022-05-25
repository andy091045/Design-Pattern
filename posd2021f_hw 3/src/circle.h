#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include "./iterator/iterator.h"
#include "./iterator/null_iterator.h"
#include "./shape.h"
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

    double area() const override { return pow(_radius, 2) * M_PI; }

    double perimeter() const override { return 2 * M_PI * _radius; }

    std::string info() const override
    {
        double _r = round(_radius * 100);
        _r = _r / 100;
        std::stringstream Cirstring;
        Cirstring << "Circle ("
                  << std::fixed << std::setprecision(2) << _r
                  << ")";
        return Cirstring.str();
    }

    Iterator *createIterator() override
    {
        return new NullIterator();
    }

private:
    double _radius;
};

#endif