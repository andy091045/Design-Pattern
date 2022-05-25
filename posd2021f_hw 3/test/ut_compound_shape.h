#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/two_dimensional_vector.h"
#include "../src/triangle.h"
#include "../src/utility.h"
#include "../src/compound_shape.h"

TEST(CaseCompoundShape, Creation)
{
    CompoundShape *cs1 = new CompoundShape();
    cs1->addShape(new Circle(1.1));
    cs1->addShape(new Rectangle(3.14, 4));
    // EXPECT_EQ(2, cs1->count());
    EXPECT_NEAR(3.80132711084 + 12.56, cs1->area(), 0.001);
}

TEST(CaseCompoundShape, info)
{
    CompoundShape *cs1 = new CompoundShape();
    cs1->addShape(new Circle(1.1));
    cs1->addShape(new Rectangle(3.14, 4));
    EXPECT_EQ("CompoundShape\n{\nCircle (1.10)\nRectangle (3.14 4.00)\n}", cs1->info());
}

// TEST(CaseCompoundShape, info)
// {
//     CompoundShape *cs1 = new CompoundShape();
//     cs1->addShape(new Circle(1.1));
//     cs1->addShape(new Rectangle(3.14, 4));
//     EXPECT_EQ("CompoundShape\n{\nCircle (1.10)\nRectangle (3.14 4.00)\n}\n", cs1->info());
// }

TEST(CaseCompoundShape, Iterator)
{
    Shape *c1 = new Circle(1.0);
    Shape *c2 = new Circle(1.0);
    Shape *s = new Rectangle(5.0, 5.0);

    CompoundShape *cs1 = new CompoundShape();
    cs1->addShape(c1);
    cs1->addShape(c2);
    cs1->addShape(s);

    Iterator *it = cs1->createIterator();

    it->first();
    EXPECT_EQ(c1, it->currentItem());

    it->next();
    EXPECT_EQ(c2, it->currentItem());

    it->next();
    EXPECT_EQ(s, it->currentItem());

    it->next();
    EXPECT_TRUE(it->isDone());
}

TEST(CaseCompoundShape, IteratorDeleteShape)
{
    Shape *c1 = new Circle(1.0);
    Shape *c2 = new Circle(1.0);
    Shape *s = new Rectangle(5.0, 5.0);

    CompoundShape *cs1 = new CompoundShape();
    cs1->addShape(c1);
    cs1->addShape(c2);
    cs1->addShape(s);
    cs1->deleteShape(s);

    Iterator *it = cs1->createIterator();

    it->first();
    EXPECT_EQ(c1, it->currentItem());

    it->next();
    EXPECT_EQ(c2, it->currentItem());

    it->next();
    EXPECT_TRUE(it->isDone());
}
