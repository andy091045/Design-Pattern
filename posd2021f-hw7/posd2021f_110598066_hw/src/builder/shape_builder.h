#pragma once

// #include "../shape.h"

#include "../circle.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "../two_dimensional_vector.h"
#include "../compound_shape.h"

#include <stack>
#include <list>

class ShapeBuilder
{
public:
    // assignment6
    static ShapeBuilder *getInstance()
    {
        if (_instance == nullptr)
        {
            _instance = new ShapeBuilder();
        }

        return _instance;
    }

    ~ShapeBuilder()
    {
        this->reset();
    }

    void buildCircle(double radius)
    {

        _shapes.push(new Circle(radius));
    }

    void buildRectangle(double length, double width)
    {

        _shapes.push(new Rectangle(length, width));
    }

    void buildTriangle(double x1, double y1, double x2, double y2)
    {

        TwoDimensionalVector vec1(x1, y1);
        TwoDimensionalVector vec2(x2, y2);
        _shapes.push(new Triangle(vec1, vec2));
    }

    void buildCompoundBegin()
    {

        _shapes.push(new CompoundShape());
    }

    void buildCompoundEnd()
    {
        std::list<Shape *> components;

        while (typeid(*_shapes.top()) != typeid(CompoundShape) ||
               (!_shapes.top()->createIterator()->isDone() &&
                typeid(*_shapes.top()) == typeid(CompoundShape)))
        {
            components.push_back(_shapes.top());
            _shapes.pop();
        }
        Shape *compound = _shapes.top();
        for (auto it = components.rbegin(); it != components.rend(); it++)
        {
            compound->addShape(*it);
        }
    }

    Shape *getShape()
    {
        return _shapes.top();
    }

    // assignment6
    void reset() { _instance = 0; }

private:
    std::stack<Shape *> _shapes;

    // assignment6
    static inline ShapeBuilder *_instance = nullptr;
    ShapeBuilder(){};
};
