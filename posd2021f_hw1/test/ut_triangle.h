#include <gtest/gtest.h>
#include "../src/triangle.h"
TEST(CaseTriangle, area)
{
    TwoDimensionalVector a(1.00, 0.00);
    TwoDimensionalVector b(0.00, 1.00);
    Triangle t(a, b);
    ASSERT_NEAR(0.5, t.area(), 0.001);
}

TEST(CaseTriangle, perimeter)
{
    TwoDimensionalVector a(1.00, 0.00);
    TwoDimensionalVector b(0.00, 1.00);
    Triangle t(a, b);
    ASSERT_NEAR(3.414, t.perimeter(), 0.001);
}

TEST(CaseTriangle, info)
{
    TwoDimensionalVector a(3.00, 12.43);
    TwoDimensionalVector b(17.57, -4.00);
    Triangle t(a, b);
    EXPECT_EQ("Triangle ([3.00,12.43] [17.57,-4.00])", t.info());
}

TEST(CaseTriangle, Format)
{
    TwoDimensionalVector a(0, 0);
    TwoDimensionalVector b(10.00, 5.00);
    ASSERT_ANY_THROW(Triangle(a, b));
}