#ifndef COMPOUNDSHAPE_H
#define COMPOUNDSHAPE_H
#include "list"
#include "./shape.h"
#include "./iterator/iterator.h"
#include "./iterator/compound_iterator.h"
class CompoundShape : public Shape
{
public:
    ~CompoundShape() {}

    double area() const override
    {
        double result = 0;
        for (std::list<Shape *>::const_iterator it = CompoundShapeList.begin(); it != CompoundShapeList.end(); it++)
        {
            result += (*it)->area();
        }
        return result;
    }

    double perimeter() const override
    {
        double resultP = 0;
        for (std::list<Shape *>::const_iterator it = CompoundShapeList.begin(); it != CompoundShapeList.end(); it++)
        {
            resultP += (*it)->perimeter();
        }
        return resultP;
    }

    std::string info() const override
    {
        std::string Ctext;
        Ctext += "CompoundShape\n{\n";
        for (std::list<Shape *>::const_iterator it = CompoundShapeList.begin(); it != CompoundShapeList.end(); it++)
        {
            Ctext += (*it)->info();
            Ctext += "\n";
        }
        Ctext += "}";
        return Ctext;
    }

    Iterator *createIterator() override
    {
        return new CompoundIterator(CompoundShapeList.begin(), CompoundShapeList.end());
    }

    void addShape(Shape *shape) override
    {
        CompoundShapeList.push_back(shape);
    }

    void deleteShape(Shape *shape) override
    {
        CompoundShapeList.pop_back();
    }

private:
    std::list<Shape *> CompoundShapeList;
};
#endif