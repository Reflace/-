#include "googletest/googletest/include/gtest/gtest.h"
#include "Parallelepiped.hpp"
#include "PriorityQueue.hpp"

TEST(Group1, test1) {
    PriorityQueue<double> pq;
    pq.push(3.4); pq.push(-0.4); pq.push(2.7);
    pq.push(1.8); pq.push(-2.1); pq.push(1.0);
    pq.push(4.2); pq.push(-5.0); pq.push(1.4);
    ASSERT_DOUBLE_EQ(pq.size(), 9);
    ASSERT_DOUBLE_EQ(pq.pop(), 4.2);
}

TEST(Group1, test2) {
    PriorityQueue<double> pq;
    pq.push(3.4); pq.push(-0.4); pq.push(2.7);
    ASSERT_DOUBLE_EQ(pq.size(), 3);
    pq.pop(); pq.pop();
    ASSERT_DOUBLE_EQ(pq.size(), 1);
    ASSERT_DOUBLE_EQ(pq.pop(), -0.4);
}

TEST(Group1, test3) {
    PriorityQueue<Parallelepiped> pq;
    Parallelepiped A(2, 2, 5), B(4, 1, 5), C(5, 8, 10), D(1, 1, 2), E(3, 8, 5), F(1, 9, 4);
    pq.push(A); pq.push(B); pq.push(C), pq.push(D); pq.push(E); pq.push(F);
    ASSERT_DOUBLE_EQ(pq.size(), 6);
    pq.pop(); pq.pop();
    ASSERT_DOUBLE_EQ(pq.size(), 4);
    ASSERT_DOUBLE_EQ(pq.pop().getVolume(), 36);
}

TEST(Group2, test1) {
    Parallelepiped A(1, 2, 3), B(2, 3, 1);
    ASSERT_TRUE(A == B);
}

int main(int argc, char **argv)
{   
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); 
}