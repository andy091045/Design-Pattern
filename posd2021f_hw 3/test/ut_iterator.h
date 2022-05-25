#include "../src/iterator/null_iterator.h"

TEST(CaseNullIterator, NullIterator)
{
    Iterator *it = new NullIterator();
    ASSERT_TRUE(it->isDone());
    delete it;
}

// Create a new repository

// git clone "網址"
// cd posd2021f_110598066_test
// touch README.md
// git add README.md
// git commit -m "add README"
// git push -u origin master

// --------------------------------------------------------------------------------------------
// Push an existing folder

// cd existing_folder
// git init
// git remote add origin "網址"
// git add .
// git commit -m "Initial commit"
// git push -u origin master

// --------------------------------------------------------------------------------------------
// Push an existing Git repository

// cd existing_repo
// git remote rename origin old-origin
// git remote add origin "網址"
// git push -u origin --all
// git push -u origin --tags

//getResult問題

// TEST(CaseVisitor, OutputVisitorInfo)
// {
//     //CompoundShape
//     Shape *c3 = new Circle(2.0);
//     Shape *s2 = new Square(2.0);
//     Shape *shapes[2] = {c3, s2};
//     CompoundShape *cs1 = new CompoundShape(shapes, 2);

//     Shape *c1 = new Circle(1.0);
//     Shape *c2 = new Circle(1.1);
//     Shape *s1 = new Square(1.1);

//     Shape *shapes2[4] = {c1, c2, s1, cs1};
//     CompoundShape *cs2 = new CompoundShape(shapes2, 4);
//     SelectShapeVisitor *visitor = new SelectShapeVisitor([](Shape *shape)
//                                                          { return shape; });
//     cs2->accept(visitor);
//     Shape *result = visitor->getResult();
//     ASSERT_EQ("CompoundShape\n{\n Circle (1.0)\n Circle (1.1)\n Square (1.1)\n CompoundShape\n {\n  Circle(2.0)\n  Square(2.0)\n }\n}", result);
//     delete c1;
//     delete c2;
//     delete c3;
//     delete s1;
//     delete s2;
//     delete shapes;
//     delete shapes2;
//     delete cs1;
//     delete cs2;
// }
