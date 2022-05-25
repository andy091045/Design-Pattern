#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/utility.h"
#include "../src/compound_shape.h"

TEST(CaseUtility, SelectShape)
{
    Shape *c1 = new Circle(1.0);
    Shape *c2 = new Circle(1.0);
    Shape *s = new Rectangle(5.0, 5.0);
    CompoundShape *cs1 = new CompoundShape();
    cs1->addShape(c1);
    cs1->addShape(c2);
    cs1->addShape(s);

    Shape *result = selectShape(cs1, [](Shape *shape)
                                { return shape->area() > 20.0 && shape->area() < 30.0; });

    ASSERT_EQ(s, result);
}
