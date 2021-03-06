#include "../src/triangle.h"
#include "../src/iterator/null_iterator.h"
#include "../src/visitor/shape_visitor.h"
#include "../src/visitor/shape_info_visitor.h"

TEST(CaseTriangle, Area)
{
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle t(vec1, vec2);
    ASSERT_NEAR(6.0, t.area(), 0.01);
}

TEST(CaseTriangle, Perimeter)
{
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle t(vec1, vec2);
    ASSERT_NEAR(12.0, t.perimeter(), 0.01);
}

TEST(CaseTriangle, Perimeter2)
{
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle t(vec1, vec2);
    ASSERT_NEAR(12.0, t.perimeter(), 0.01);
}

TEST(CaseTriangle, Info)
{
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle t(vec1, vec2);
    ASSERT_TRUE("Triangle ([3.00,4.00] [3.00,0.00])" == t.info());
}

TEST(CaseTriangle, Info1)
{
    TwoDimensionalVector vec1(3, 12.433);
    TwoDimensionalVector vec2(17.56789, -4);
    Triangle t(vec1, vec2);
    ASSERT_TRUE("Triangle ([3.00,12.43] [17.57,-4.00])" == t.info());
}

TEST(CaseTriangle, NonParallel)
{
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(-3.0, -4.0);
    ASSERT_ANY_THROW(Triangle t(vec1, vec2));
}

TEST(CaseTriangle, NonParallel2)
{
    TwoDimensionalVector vec1(1.0, 1.0);
    TwoDimensionalVector vec2(9.0, 9.0);
    ASSERT_ANY_THROW(Triangle t(vec1, vec2));
}

TEST(CaseTriangle, IsNullIterator)
{
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle t(vec1, vec2);
    ASSERT_EQ(typeid(NullIterator), typeid(*t.createIterator()));
}

TEST(CaseTriangle, NullIterator_isDoneTrue)
{
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle t(vec1, vec2);
    ASSERT_TRUE(t.createIterator()->isDone());
}

TEST(CaseTriangle, NullIterator_First_Exception)
{
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle t(vec1, vec2);
    ASSERT_ANY_THROW(t.createIterator()->first());
}

TEST(CaseTriangle, NullIterator_Next_Exception)
{
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle t(vec1, vec2);
    ASSERT_ANY_THROW(t.createIterator()->next());
}

TEST(CaseTriangle, NullIterator_Current_Exception)
{
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle t(vec1, vec2);
    ASSERT_ANY_THROW(t.createIterator()->next());
}

TEST(CaseTriangle, AddShape_Exception)
{
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle t(vec1, vec2);
    Triangle *t2 = new Triangle(vec1, vec2);
    ASSERT_ANY_THROW(t.addShape(t2));

    delete t2;
}

TEST(CaseTriangle, DeleteShape_Exception)
{
    TwoDimensionalVector vec1(3.0, 4.0);
    TwoDimensionalVector vec2(3.0, 0.0);
    Triangle t(vec1, vec2);
    Triangle *t2 = new Triangle(vec1, vec2);
    ASSERT_ANY_THROW(t.deleteShape(t2));

    delete t2;
}

TEST(CaseTriangle, VisitTriangle)
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