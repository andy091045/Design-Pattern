#include <gtest/gtest.h>
#include "../src/list_item.h"
TEST(CaseListItem, getText)
{
    ListItem a("apple");
    Article *t = new ListItem("apple");
    EXPECT_EQ("- apple", a.getText());
    EXPECT_EQ("- apple", t->getText());
}

TEST(CaseListItem, getLevel)
{
    ListItem a("apple");
    Article *t = new ListItem("apple");
    EXPECT_EQ(0, a.getLevel());
    EXPECT_EQ(0, t->getLevel());
}

TEST(CaseListItem, add)
{
    ListItem a("apple");
    Article *t1 = new ListItem("apple");
    Article *t2 = new ListItem("orange");
    ASSERT_ANY_THROW(a.add(t2));
    ASSERT_ANY_THROW(t1->add(t2));
}