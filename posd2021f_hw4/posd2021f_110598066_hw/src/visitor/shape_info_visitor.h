#pragma once

#include <string>
#include <sstream>

#include "./shape_visitor.h"
#include "../circle.h"
#include "../compound_shape.h"
#include "../rectangle.h"
#include "../triangle.h"

// template <class ShapeConstraint>
// class ShapeInfoVisitor : public ShapeVisitor
// {
// public:
//     ShapeInfoVisitor() : _constraint(nullptr) {}
//     ShapeInfoVisitor(ShapeConstraint constraint) : _constraint(constraint) {}
//     void visitCircle(Circle *circle);
//     void visitRectangle(Rectangle *rectangle) {}
//     void visitTriangle(Triangle *triangle) {}
//     void visitCompoundShape(CompoundShape *compoundShape) {}
//     std::string getResult();

// private:
//     ShapeConstraint _constraint;
//     int depth = 0;
//     std::string result = "";
// };

// template <typename ShapeConstraint>
// void ShapeInfoVisitor<ShapeConstraint>::visitCircle(Circle *c)
// {
//     if (_constraint(c))
//     {
//         std::stringstream stream;
//         stream << std::fixed << std::setprecision(2) << c->_radius;
//         result = "Circle (" + stream.str() + ")\n";
//     }
// }

// template <typename ShapeConstraint>
// std::string ShapeInfoVisitor<ShapeConstraint>::getResult()
// {
//     return result;
// }

class ShapeInfoVisitor : public ShapeVisitor
{
public:
    ShapeInfoVisitor() {}
    void visitCircle(Circle *circle)
    {
        for (int i = 0; i < depth; i++)
        {
            result += "  ";
        }
        result = result + circle->info() + "\n";
    }
    void visitRectangle(Rectangle *rectangle)
    {
        for (int i = 0; i < depth; i++)
        {
            result += "  ";
        }
        result = result + rectangle->info() + "\n";
    }
    void visitTriangle(Triangle *triangle)
    {
        for (int i = 0; i < depth; i++)
        {
            result += "  ";
        }
        result = result + triangle->info() + "\n";
    }
    void visitCompoundShape(CompoundShape *compoundShape)
    {
        for (int i = 0; i < depth; i++)
        {
            result += "  ";
        }
        result += "CompoundShape{\n";
        depth++;
        Iterator *it = compoundShape->createIterator();
        for (it->first(); !it->isDone(); it->next())
        {
            it->currentItem()->accept(this);
        }
        depth--;
        for (int i = 0; i < depth; i++)
        {
            result += "  ";
        }
        depth--;
        result += "}\n";
    }
    std::string getResult() { return result; };

private:
    int depth = 0;
    std::string result = "";
};
