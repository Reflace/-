#include "googletest/googletest/include/gtest/gtest.h"
#include "googletest/googletest/include/gtest/gtest-assertion-result.h"
#include "Set.h"
using namespace std;

TEST(Group1, test1) {
    Set s(10, 20);
    s.add(11);
    ASSERT_TRUE(s.poisk(11));
}
TEST(Group1, test2) {
    Set s(10, 20);
    s.add(11);
    s.del(11);
    ASSERT_FALSE(s.poisk(11));
}
TEST(Group1, test3) {
    Set s1(10, 20);
    Set s2(10, 20);
    s1.add(11); s1.add(15); s1.add(18);
    s2.add(11); s2.add(12);
    Set s3 = s1 + s2;
    ASSERT_TRUE(s3.poisk(11) && s3.poisk(12) && s3.poisk(15) &&
                s3.poisk(18) && !s3.poisk(10) && !s3.poisk(14));
}
TEST(Group1, test4) {
    Set s1(10, 20);
    Set s2(10, 20);
    s1.add(11); s1.add(15); s1.add(18);
    s2.add(11); s2.add(12);
    Set s3 = s1 * s2;
    ASSERT_TRUE(s3.poisk(11) && !s3.poisk(12) && !s3.poisk(15) &&
                !s3.poisk(18));
}
TEST(Group1, test5) {
    Set s1(10, 20);
    Set s2(10, 20);
    s1.add(11); s1.add(15); s1.add(18);
    s2.add(11); s2.add(12);
    Set s3 = s1 - s2;
    ASSERT_TRUE(!s3.poisk(11) && !s3.poisk(12) && s3.poisk(15) &&
                s3.poisk(18));
}
TEST(Group1, test6) {
    Set s1(10, 20);
    s1.add(11); s1.add(15); s1.add(18);
    Set s3 = ~s1;
    ASSERT_TRUE(!s3.poisk(11) && !s3.poisk(15) && !s3.poisk(18));
}

int main(int argc, char **argv)
{   
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); 
}