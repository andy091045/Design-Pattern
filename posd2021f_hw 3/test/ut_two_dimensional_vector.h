#include <vector>
#include "../src/two_dimensional_vector.h"
TEST(CaseTwoDimensionalVector, x)
{
    TwoDimensionalVector v(10.00, 5.00);
    ASSERT_NEAR(10.00, v.x(), 0.001);
}

TEST(CaseTwoDimensionalVector, y)
{
    TwoDimensionalVector v(10.00, 5.00);
    ASSERT_NEAR(5.00, v.y(), 0.001);
}

TEST(CaseTwoDimensionalVector, info)
{
    TwoDimensionalVector v(3.00, 12.43);
    EXPECT_EQ("[3.00,12.43]", v.info());
}

TEST(CaseTwoDimensionalVector, length)
{
    TwoDimensionalVector v(10.00, 5.00);
    ASSERT_NEAR(11.180, v.length(), 0.001);
}

TEST(CaseTwoDimensionalVector, subtract)
{
    TwoDimensionalVector a(10.00, 5.00);
    TwoDimensionalVector b(1.00, 1.00);
    TwoDimensionalVector c(9.00, 4.00);
    a.subtract(b);
    EXPECT_EQ(c.x(), a.x());
    EXPECT_EQ(c.y(), a.y());
}

TEST(CaseTwoDimensionalVector, dot)
{
    TwoDimensionalVector a(10.00, 5.00);
    TwoDimensionalVector b(1.00, 1.00);
    ASSERT_NEAR(15.00, a.dot(b), 0.001);
}

TEST(CaseTwoDimensionalVector, cross)
{
    TwoDimensionalVector a(10.00, 5.00);
    TwoDimensionalVector b(1.00, 1.00);
    ASSERT_NEAR(5.00, a.cross(b), 0.001);
}
