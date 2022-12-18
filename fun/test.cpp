#include "googletest/googletest/include/gtest/gtest.h"
#include "googletest/googletest/include/gtest/gtest-assertion-result.h"
#include "fun.hpp"
using namespace std;

TEST(Group1, test1) {
    ASSERT_DOUBLE_EQ(fun1(-10.), -3);
}
TEST(Group1, test2) {
    ASSERT_DOUBLE_EQ(fun1(-3.), 0);
}
TEST(Group1, test3) {
    ASSERT_DOUBLE_EQ(fun1(0.), -3.);
}
TEST(Group1, test4) {
    ASSERT_DOUBLE_EQ(fun1(4.), 1);
}
TEST(Group1, test5) {
    ASSERT_DOUBLE_EQ(fun1(5.), 3);
}

TEST(Group2, test1) {
    ASSERT_TRUE(fun2(-2, 2));
}
TEST(Group2, test2) {
    ASSERT_TRUE(fun2(2, -2));
}
TEST(Group2, test3) {
    ASSERT_FALSE(fun2(-6, 1));
}

int main(int argc, char **argv)
{   
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); 
}