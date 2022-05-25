#include "../../src/builder/shape_parser.h"
#include "../../src/shape.h"
TEST(CaseParser, ParseCircle)
{
    ShapeParser *parser = new ShapeParser("test/data/circle.txt");
    ASSERT_EQ("apple", parser->read());
    Shape *result = parser->getShape();
    ASSERT_NEAR(1 * 1 * M_PI, result->area(), 0.01);
    delete result;
    delete parser;
}

TEST(CaseParser, BuildComplexCompound)
{
    ShapeParser *parser = new ShapeParser("test/data/complex_compound.txt");
    Shape *result = parser->getShape();
    ASSERT_NEAR(43.403185307179584, result->area(), 0.01);
    delete result;
    delete parser;
}

TEST(CaseParser, BuildEmptyCompound)
{
    ShapeParser *parser = new ShapeParser("test/data/empty_compound.txt");
    Shape *result = parser->getShape();
    ASSERT_NEAR(0, result->area(), 0.01);
    delete result;
    delete parser;
}

TEST(CaseParser, BuildRectangle)
{
    ShapeParser *parser = new ShapeParser("test/data/rectangle.txt");
    Shape *result = parser->getShape();
    ASSERT_NEAR(12.56, result->area(), 0.01);
    delete result;
    delete parser;
}

TEST(CaseParser, BuildSimpleCompound)
{
    ShapeParser *parser = new ShapeParser("test/data/simple_compound.txt");
    Shape *result = parser->getShape();
    ASSERT_NEAR(21.701592653589792, result->area(), 0.01);
    delete result;
    delete parser;
}

TEST(CaseParser, BuildTriangle)
{
    ShapeParser *parser = new ShapeParser("test/data/triangle.txt");
    Shape *result = parser->getShape();
    ASSERT_NEAR(6, result->area(), 0.01);
    delete result;
    delete parser;
}