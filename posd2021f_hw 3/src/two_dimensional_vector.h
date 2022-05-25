#ifndef TWODIMENSIONALVECTOR_H
#define TWODIMENSIONALVECTOR_H

#include <math.h>
#include <vector>
#include <iostream>
#include "shape.h"
#include "./iterator/iterator.h"
#include "./iterator/null_iterator.h"
#include "./shape.h"
class TwoDimensionalVector
{
public:
    TwoDimensionalVector(double x, double y)
    {
        _x = x - 0;
        _y = y - 0;
        vect.push_back(_x);
        vect.push_back(_y);
    }

    double x() const { return _x; }

    double y() const { return _y; }

    double length() const { return sqrt(pow(_x, 2) + pow(_y, 2)); }
    double length(TwoDimensionalVector vec) const { return sqrt(pow(vec._x, 2) + pow(vec._y, 2)); }

    double dot(TwoDimensionalVector vec) const
    {
        int product = 0;
        for (int i = 0; i < 2; i++)
            product = product + this->vect[i] * vec.vect[i];
        return product;
    }

    double cross(TwoDimensionalVector vec) const
    {
        int product = 0;
        product = this->vect[0] * vec.vect[1] - this->vect[1] * vec.vect[0];
        return product;
    }

    TwoDimensionalVector subtract(TwoDimensionalVector vec)
    {
        this->_x = this->_x - vec._x;
        this->_y = this->_y - vec._y;
        return *this;
    }

    std::string info() const
    {
        double x = round(_x * 100);
        x = x / 100;
        double y = round(_y * 100);
        y = y / 100;
        std::stringstream Twostring;
        Twostring << "["
                  << std::fixed << std::setprecision(2) << x << "," << std::fixed << std::setprecision(2) << y
                  << "]";
        return Twostring.str();
    }

    double _x;
    double _y;
    std::vector<double> vect;
};
#endif
