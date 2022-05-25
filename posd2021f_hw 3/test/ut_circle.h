#include "../src/circle.h"

TEST(CaseCircle, Area)
{
    Circle c(10.0);
    ASSERT_NEAR(314.159, c.area(), 0.001);
}

TEST(CaseCircle, perimeter)
{
    Circle c(10.0);
    ASSERT_NEAR(62.831, c.perimeter(), 0.001);
}

TEST(CaseCircle, info)
{
    Circle c(1.10);
    EXPECT_EQ("Circle (1.10)", c.info());
}

TEST(CaseCircle, Format)
{
    ASSERT_ANY_THROW(Circle(-10.0));
}

TEST(CaseCircle, NullIterator)
{
    Circle c(10.0);
    ASSERT_TRUE(c.createIterator()->isDone());
}