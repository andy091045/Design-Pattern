#include "../../src/builder/scanner.h"

TEST(CaseScanner, ScanIllegalWordShouldIgnore)
{
    std::string input = "I Circle eee ,tt{t3.14159a";

    Scanner scanner(input);
    std::string first = scanner.next();  // `first` is "Circle"
    std::string second = scanner.next(); // `second` is ","
    double third = scanner.nextDouble(); // `third` is 3.14159

    ASSERT_EQ("Circle", first);
    ASSERT_EQ(",", second);
    ASSERT_EQ(3.14159, third);
}

TEST(CaseScanner, ScanCircleCorrectly)
{
    std::string input = "Circle";

    Scanner scanner(input);
    std::string first = scanner.next(); // `first` is "Circle"

    ASSERT_EQ("Circle", first);
}

TEST(CaseScanner, ScanRectangleCorrectly)
{
    std::string input = "Rectangle";

    Scanner scanner(input);
    std::string first = scanner.next(); // `first` is "Circle"

    ASSERT_EQ("Rectangle", first);
}

TEST(CaseScanner, ScanTriangleCorrectly)
{
    std::string input = "Triangle";

    Scanner scanner(input);
    std::string first = scanner.next(); // `first` is "Circle"

    ASSERT_EQ("Triangle", first);
}

TEST(CaseScanner, IsDoneShouldBeCorrect)
{
    std::string input = "I Circle eee ,tt{t3.14159a";

    Scanner scanner(input);
    std::string first = scanner.next();  // `first` is "Circle"
    std::string second = scanner.next(); // `second` is ","
    double third = scanner.nextDouble(); // `third` is 3.14159
    std::string fourth = scanner.next();

    ASSERT_EQ(true, scanner.isDone());
}

TEST(CaseScanner, NextShouldThrowExceptionWhenIsDone)
{
    std::string input = "I Circle eee ,tt{t3.14159a";

    Scanner scanner(input);
    std::string first = scanner.next();  // `first` is "Circle"
    std::string second = scanner.next(); // `second` is ","
    double third = scanner.nextDouble(); // `third` is 3.14159
    std::string fourth = scanner.next();

    ASSERT_ANY_THROW(scanner.next());
}

TEST(CaseScanner, NextDoubleShouldThrowExceptionWhenIsDone)
{
    std::string input = "I Circle eee ,tt{t3.14159a";

    Scanner scanner(input);
    std::string first = scanner.next();  // `first` is "Circle"
    std::string second = scanner.next(); // `second` is ","
    double third = scanner.nextDouble(); // `third` is 3.14159

    ASSERT_ANY_THROW(scanner.nextDouble());
}

TEST(CaseScanner, ScanEmptyCompoundCorrectly)
{
    std::string input = "CompoundShape {}";

    Scanner scanner(input);
    std::string first = scanner.next();
    std::string second = scanner.next();
    std::string third = scanner.next();

    ASSERT_EQ("CompoundShape", first);
    ASSERT_EQ("{", second);
    ASSERT_EQ("}", third);
}

TEST(CaseScanner, ScanSimpleCompoundCorrectly)
{
    std::string input = "CompoundShape { Circle(1.0)  Rectangle(3.14 4.00) Triangle([ 3, 0 ][0, 4])}";

    Scanner scanner(input);
    std::string s1 = scanner.next();
    std::string s2 = scanner.next();
    std::string s3 = scanner.next();
    std::string s4 = scanner.next();
    double n1 = scanner.nextDouble();
    std::string s5 = scanner.next();
    std::string s6 = scanner.next();
    std::string s7 = scanner.next();
    double n2 = scanner.nextDouble();
    double n3 = scanner.nextDouble();
    std::string s8 = scanner.next();
    std::string s9 = scanner.next();
    std::string s10 = scanner.next();
    std::string s11 = scanner.next();
    double n4 = scanner.nextDouble();
    std::string s12 = scanner.next();
    double n5 = scanner.nextDouble();
    std::string s13 = scanner.next();
    std::string s14 = scanner.next();

    double n6 = scanner.nextDouble();
    std::string s15 = scanner.next();
    double n7 = scanner.nextDouble();

    std::string s16 = scanner.next();
    std::string s17 = scanner.next();
    std::string s18 = scanner.next();

    ASSERT_EQ("CompoundShape", s1);
    ASSERT_EQ("{", s2);
    ASSERT_EQ("Circle", s3);
    ASSERT_EQ("(", s4);
    ASSERT_EQ(1.0, n1);
    ASSERT_EQ(")", s5);
    ASSERT_EQ("Rectangle", s6);
    ASSERT_EQ("(", s7);
    ASSERT_EQ(3.14, n2);
    ASSERT_EQ(4.00, n3);
    ASSERT_EQ(")", s8);
    ASSERT_EQ("Triangle", s9);
    ASSERT_EQ("(", s10);
    ASSERT_EQ("[", s11);
    ASSERT_EQ(3, n4);
    ASSERT_EQ(",", s12);
    ASSERT_EQ(0, n5);
    ASSERT_EQ("]", s13);
    ASSERT_EQ("[", s14);
    ASSERT_EQ(0, n6);
    ASSERT_EQ(",", s15);
    ASSERT_EQ(4, n7);
    ASSERT_EQ("]", s16);
    ASSERT_EQ(")", s17);
    ASSERT_EQ("}", s18);
}

TEST(CaseScanner, ScanComplexCompoundCorrectly)
{
    std::string input = "CompoundShape { Circle (1.0) Triangle ([3,0] [0,4]) CompoundShape {  Circle (1.0)  Rectangle (3.14 4.00)  Triangle ([3,0] [0,4]) }  Rectangle (3.14 4.00)}";

    Scanner scanner(input);
    std::string s1 = scanner.next();
    std::string s2 = scanner.next();
    std::string s3 = scanner.next();
    std::string s4 = scanner.next();
    double n1 = scanner.nextDouble();
    std::string s5 = scanner.next();

    std::string s9 = scanner.next();
    std::string s10 = scanner.next();
    std::string s11 = scanner.next();
    double n4 = scanner.nextDouble();
    std::string s12 = scanner.next();
    double n5 = scanner.nextDouble();
    std::string s13 = scanner.next();
    std::string s14 = scanner.next();

    double n6 = scanner.nextDouble();
    std::string s15 = scanner.next();
    double n7 = scanner.nextDouble();

    std::string s16 = scanner.next();
    std::string s17 = scanner.next();

    //第二個compoundShape
    std::string ss1 = scanner.next();
    std::string ss2 = scanner.next();
    std::string ss3 = scanner.next();
    std::string ss4 = scanner.next();
    double nn1 = scanner.nextDouble();
    std::string ss5 = scanner.next();
    std::string ss6 = scanner.next();
    std::string ss7 = scanner.next();
    double nn2 = scanner.nextDouble();
    double nn3 = scanner.nextDouble();
    std::string ss8 = scanner.next();
    std::string ss9 = scanner.next();
    std::string ss10 = scanner.next();
    std::string ss11 = scanner.next();
    double nn4 = scanner.nextDouble();
    std::string ss12 = scanner.next();
    double nn5 = scanner.nextDouble();
    std::string ss13 = scanner.next();
    std::string ss14 = scanner.next();
    double nn6 = scanner.nextDouble();
    std::string ss15 = scanner.next();
    double nn7 = scanner.nextDouble();
    std::string ss16 = scanner.next();
    std::string ss17 = scanner.next();
    std::string ss18 = scanner.next();

    // Rectangle
    std::string sss6 = scanner.next();
    std::string sss7 = scanner.next();
    double nnn2 = scanner.nextDouble();
    double nnn3 = scanner.nextDouble();
    std::string sss8 = scanner.next();

    std::string s18 = scanner.next();

    ASSERT_EQ("CompoundShape", s1);
    ASSERT_EQ("{", s2);
    ASSERT_EQ("Circle", s3);
    ASSERT_EQ("(", s4);
    ASSERT_EQ(1.0, n1);
    ASSERT_EQ(")", s5);

    ASSERT_EQ("Triangle", s9);
    ASSERT_EQ("(", s10);
    ASSERT_EQ("[", s11);
    ASSERT_EQ(3, n4);
    ASSERT_EQ(",", s12);
    ASSERT_EQ(0, n5);
    ASSERT_EQ("]", s13);
    ASSERT_EQ("[", s14);
    ASSERT_EQ(0, n6);
    ASSERT_EQ(",", s15);
    ASSERT_EQ(4, n7);
    ASSERT_EQ("]", s16);
    ASSERT_EQ(")", s17);

    //第二個compoundShape
    ASSERT_EQ("CompoundShape", ss1);
    ASSERT_EQ("{", ss2);
    ASSERT_EQ("Circle", ss3);
    ASSERT_EQ("(", ss4);
    ASSERT_EQ(1.0, nn1);
    ASSERT_EQ(")", ss5);
    ASSERT_EQ("Rectangle", ss6);
    ASSERT_EQ("(", ss7);
    ASSERT_EQ(3.14, nn2);
    ASSERT_EQ(4.00, nn3);
    ASSERT_EQ(")", ss8);
    ASSERT_EQ("Triangle", ss9);
    ASSERT_EQ("(", ss10);
    ASSERT_EQ("[", ss11);
    ASSERT_EQ(3, nn4);
    ASSERT_EQ(",", ss12);
    ASSERT_EQ(0, nn5);
    ASSERT_EQ("]", ss13);
    ASSERT_EQ("[", ss14);
    ASSERT_EQ(0, nn6);
    ASSERT_EQ(",", ss15);
    ASSERT_EQ(4, nn7);
    ASSERT_EQ("]", ss16);
    ASSERT_EQ(")", ss17);
    ASSERT_EQ("}", ss18);
    //------------------------------

    ASSERT_EQ("Rectangle", sss6);
    ASSERT_EQ("(", sss7);
    ASSERT_EQ(3.14, nnn2);
    ASSERT_EQ(4.00, nnn3);
    ASSERT_EQ(")", sss8);

    ASSERT_EQ("}", s18);
}