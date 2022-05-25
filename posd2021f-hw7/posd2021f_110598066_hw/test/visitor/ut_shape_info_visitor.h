#include "../../src/circle.h"
#include "../../src/compound_shape.h"
#include "../../src/rectangle.h"
#include "../../src/two_dimensional_vector.h"
#include "../../src/triangle.h"
#include "../../src/visitor/shape_visitor.h"
#include "../../src/visitor/shape_info_visitor.h"
#include <iostream>

// typedef bool (*ShapeConstraint)(Shape *); //pointer to function

TEST(CaseShapeInfoVisitor, VisitCircle)
{
    Circle *c1 = new Circle(1.1);
    // ShapeInfoVisitor<ShapeConstraint> *visitor = new ShapeInfoVisitor<ShapeConstraint>([](Shape *shape)
    //                                                                                    { return shape->area() > 0.0; });
    ShapeInfoVisitor visitor;
    c1->accept(&visitor);
    std::string result = visitor.getResult();
    ASSERT_EQ("Circle (1.10)\n", result);
    delete c1;
}

TEST(CaseShapeInfoVisitor, VisitRectangle)
{
    Shape *r1 = new Rectangle(3.14, 4);
    ShapeInfoVisitor visitor;
    r1->accept(&visitor);
    std::string result = visitor.getResult();
    ASSERT_EQ("Rectangle (3.14 4.00)\n", result);
    delete r1;
}

TEST(CaseShapeInfoVisitor, VisitTriangle)
{
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Shape *t = new Triangle(vec1, vec2);
    ShapeInfoVisitor visitor;
    t->accept(&visitor);
    std::string result = visitor.getResult();
    ASSERT_EQ("Triangle ([3.00,4.00] [3.00,0.00])\n", result);
    delete t;
}

TEST(CaseShapeInfoVisitor, VisitCompoundShape)
{
    CompoundShape *cs1 = new CompoundShape();
    cs1->addShape(new Circle(1.1));
    cs1->addShape(new Rectangle(3.14, 4));

    CompoundShape *cs2 = new CompoundShape();
    cs2->addShape(new Circle(12.34567));
    cs2->addShape(cs1);

    ShapeInfoVisitor visitor;
    cs2->accept(&visitor);
    std::string result = visitor.getResult();
    // std::cout << result << std::endl;
    ASSERT_EQ("CompoundShape {\n  Circle (12.35)\n  CompoundShape {\n    Circle (1.10)\n    Rectangle (3.14 4.00)\n  }\n}\n", result);
    delete cs2;
}

// TEST(CaseShapeInfoVisitor, VisitCompoundShapeError)
// {
//     CompoundShape *cs1 = new CompoundShape();
//     ShapeInfoVisitor visitor;
//     cs1->accept(&visitor);
//     std::string result = visitor.getResult();
//     std::cout << result << std::endl;
//     ASSERT_ANY_THROW(result);
//     delete cs1;
// }