#ifndef SHAPE_H
#define SHAPE_H

class Iterator;

class Shape
{
public:
    virtual ~Shape(){};

    virtual double area() const = 0;

    virtual double perimeter() const = 0;

    virtual std::string info() const = 0;

    virtual Iterator *createIterator() = 0;

    virtual void addShape(Shape *shape) {}

    virtual void deleteShape(Shape *shape) {}
};

#endif