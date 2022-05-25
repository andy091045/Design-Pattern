#include "../../src/shape.h"
#include "../../src/builder/shape_builder.h"
class CaseBuilder : public ::testing::Test
{
protected:
    const double delta = 0.001;

    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(CaseBuilder, BuildCircle)
{
    ShapeBuilder *builder = ShapeBuilder::getInstance();
    double radius = 1.0;
    builder->buildCircle(radius);
    Shape *result = builder->getShape();

    ASSERT_NEAR(1 * 1 * M_PI, result->area(), delta);
    delete result;
    delete builder;
}

TEST_F(CaseBuilder, BuildRectangle)
{
    ShapeBuilder *builder = ShapeBuilder::getInstance();
    double length = 1.0;
    double width = 2.0;
    builder->buildRectangle(length, width);
    Shape *result = builder->getShape();

    ASSERT_NEAR(1 * 2, result->area(), delta);
    delete result;
    delete builder;
}

TEST_F(CaseBuilder, BuildTriangle)
{
    ShapeBuilder *builder = ShapeBuilder::getInstance();
    double x1 = 3.0;
    double y1 = 4.0;
    double x2 = 3.0;
    double y2 = 0.0;
    builder->buildTriangle(x1, y1, x2, y2);
    Shape *result = builder->getShape();

    ASSERT_NEAR(6.0, result->area(), delta);
    delete result;
    delete builder;
}

TEST_F(CaseBuilder, BuildCompound)
{
    ShapeBuilder *builder = ShapeBuilder::getInstance();

    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildCircle(2.0);
    builder->buildCompoundEnd();
    Shape *result = builder->getShape();

    ASSERT_NEAR(1 * 1 * M_PI + 2 * 2 * M_PI, result->area(), delta);
    delete result;
    delete builder;
}

TEST_F(CaseBuilder, BuildComplexCompound)
{
    ShapeBuilder *builder = ShapeBuilder::getInstance();

    builder->buildCompoundBegin();
    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildCircle(2.0);
    builder->buildCompoundEnd();
    builder->buildRectangle(3.0, 4.0);
    builder->buildCompoundEnd();
    Shape *result = builder->getShape();

    ASSERT_NEAR(1 * 1 * M_PI + 2 * 2 * M_PI, result->createIterator()->currentItem()->area(), delta);
    delete result;
    delete builder;
}

TEST_F(CaseBuilder, BuildEmptyCompound)
{
    ShapeBuilder *builder = ShapeBuilder::getInstance();

    builder->buildCompoundBegin();
    builder->buildCompoundEnd();
    Shape *result = builder->getShape();
    ASSERT_EQ(0, result->area());
    delete result;
    delete builder;
}

// TEST_F(CaseBuilder, singleton)
// {
//     ShapeBuilder *builder = ShapeBuilder::getInstance();
//     double radius = 1.0;
//     builder->buildCircle(radius);
//     Shape *result = builder->getShape();

//     ASSERT_NEAR(1 * 1 * M_PI, result->area(), delta);
//     delete result;
//     delete builder;
// }
