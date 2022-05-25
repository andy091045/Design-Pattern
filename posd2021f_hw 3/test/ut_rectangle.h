#include "../src/rectangle.h"

TEST(CaseRectangle, area)
{
    Rectangle r(10.00, 5.00);
    ASSERT_NEAR(50.00, r.area(), 0.001);
}

TEST(CaseRectangle, perimeter)
{
    Rectangle r(10.00, 5.00);
    ASSERT_NEAR(30.00, r.perimeter(), 0.001);
}

TEST(CaseRectangle, info)
{
    Rectangle r(3.14, 4.00);
    EXPECT_EQ("Rectangle (3.14 4.00)", r.info());
}

TEST(CaseRectangle, Format)
{
    ASSERT_ANY_THROW(Rectangle(-10, 5));
}

TEST(CaseRectangle, NullIterator)
{
    Rectangle r(10.00, 5.00);
    ASSERT_TRUE(r.createIterator()->isDone());
}