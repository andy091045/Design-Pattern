#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "./iterator/iterator.h"
#include "./iterator/null_iterator.h"
#include "./shape.h"
#include <math.h>
class Rectangle : public Shape
{
public:
    Rectangle(double length, double width)
    {
        _length = length;
        _width = width;
        if (_length <= 0 || _width <= 0)
        {
            throw "Format not correct";
        }
    }

    double area() const override { return _length * _width; }

    double perimeter() const override { return 2 * (_length + _width); }

    std::string info() const override
    {
        double _l = round(_length * 100);
        _l = _l / 100;
        double _w = round(_width * 100);
        _w = _w / 100;

        std::stringstream Rectstring;
        Rectstring << "Rectangle ("
                   << std::fixed << std::setprecision(2) << _l
                   << " "
                   << std::fixed << std::setprecision(2) << _w
                   << ")";
        return Rectstring.str();
    }

    Iterator *createIterator() override
    {
        return new NullIterator();
    }

private:
    double _length;
    double _width;
};

#endif