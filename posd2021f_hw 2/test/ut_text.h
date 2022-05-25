#include <gtest/gtest.h>
#include "../src/text.h"
TEST(CaseText, getText)
{
    Text a("apple");
    Article *t = new Text("apple");
    EXPECT_EQ("apple", a.getText());
    EXPECT_EQ("apple", t->getText());
}

TEST(CaseText, getLevel)
{
    Text a("apple");
    Article *t = new Text("apple");
    EXPECT_EQ(0, a.getLevel());
    EXPECT_EQ(0, t->getLevel());
}

TEST(CaseText, add)
{
    Text a("apple");
    Article *t1 = new Text("apple");
    Article *t2 = new Text("orange");
    ASSERT_ANY_THROW(a.add(t2));
    ASSERT_ANY_THROW(t1->add(t2));
}