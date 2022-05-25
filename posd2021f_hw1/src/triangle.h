#include <vector>
#include <math.h>
#include "shape.h"
class Triangle : public Shape
{
public:
    Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2) : _vec1(vec1), _vec2(vec2), _toLength(vec1)
    {
        length1 = _vec1.length();
        length2 = _vec2.length();
        length3 = _toLength.length(_toLength.subtract(_vec2));
        length = length1 + length2 + length3;
        if (_vec1._x == 0 && _vec1._y == 0)
        {
            throw "no triangle";
        }
        else if (_vec2._x == 0 && _vec2._y == 0)
        {
            throw "no triangle";
        }
        else if (_vec1._x == 0 && _vec2._x == 0)
        {
            throw "no triangle";
        }
        else if (_vec1._y == 0 && _vec2._y == 0)
        {
            throw "no triangle";
        }

        if (_vec1._x != 0 && _vec1._y != 0 && _vec2._x != 0 && _vec2._y != 0)
        {
            double _vect1_number = _vec1._x / _vec1._y;
            double _vect2_number = _vec2._x / _vec2._y;
            if (_vect1_number == _vect2_number)
            {
                throw "no triangle";
            }
        }
    }

    double area() const
    {
        return sqrt((length / 2) * ((length / 2) - length1) * ((length / 2) - length2) * ((length / 2) - length3));
    }

    double perimeter() const
    {
        return length;
    }

    std::string info() const
    {
        double _x1 = round(_vec1._x * 100);
        _x1 = _x1 / 100;
        double _x2 = round(_vec2._x * 100);
        _x2 = _x2 / 100;
        double _y1 = round(_vec1._y * 100);
        _y1 = _y1 / 100;
        double _y2 = round(_vec2._y * 100);
        _y2 = _y2 / 100;
        std::stringstream Tristring;
        Tristring << "Triangle ("
                  << "[" << std::fixed << std::setprecision(2) << _x1 << "," << std::fixed << std::setprecision(2) << _y1 << "]"
                  << " "
                  << "[" << std::fixed << std::setprecision(2) << _x2 << "," << std::fixed << std::setprecision(2) << _y2 << "]"
                  << ")";
        return Tristring.str();
    }

private:
    TwoDimensionalVector _vec1;
    TwoDimensionalVector _vec2;
    TwoDimensionalVector _toLength;
    double length;
    double length1;
    double length2;
    double length3;
};