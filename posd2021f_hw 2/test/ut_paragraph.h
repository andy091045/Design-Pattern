#include "../src/article.h"
#include "../src/paragraph.h"
#include "../src/list_item.h"
#include "../src/text.h"
#include <gtest/gtest.h>

TEST(CaseParagraph, getText)
{
    Article *p1 = new Paragraph(2, "apple");
    EXPECT_EQ("## apple\n", p1->getText());
}

TEST(CaseParagraph, getLevel)
{
    Article *p1 = new Paragraph(2, "apple");
    EXPECT_EQ(2, p1->getLevel());
}

TEST(CaseParagraph, add)
{
    Article *p1 = new Paragraph(2, "apple");
    Article *p2 = new ListItem("orange");
    Article *p3 = new ListItem("fish");
    p1->add(p2);
    p1->add(p3);
    EXPECT_EQ("## apple\n- orange\n- fish", p1->getText());
}

TEST(CaseParagraph, addError)
{
    Article *p1 = new Paragraph(2, "apple");
    Article *p2 = new Paragraph(2, "orange");
    ASSERT_ANY_THROW(p1->add(p2));
}

TEST(CaseParagraph, add2)
{
    Article *p1 = new Paragraph(2, "apple");
    Article *p2 = new Paragraph(4, "orange");
    Article *p3 = new ListItem("orange");
    p2->add(p3);
    p1->add(p2);
    EXPECT_EQ("## apple\n#### orange\n- orange", p1->getText());
}

TEST(CaseParagraph, add3)
{
    Article *p1 = new Paragraph(2, "apple");
    Article *p2 = new Paragraph(4, "orange");
    p1->add(p2);
    EXPECT_EQ("## apple\n#### orange\n", p1->getText());
}

TEST(CaseParagraph, getTextError)
{
    ASSERT_ANY_THROW(Paragraph(0, "title"));
}