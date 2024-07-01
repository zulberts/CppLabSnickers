#include <gtest/gtest.h>
#include "../StosLib/Stack.h"

TEST(StackTest, InitEmpty) {
    Stack s;
    EXPECT_TRUE(s.isEmpty());
}

TEST(StackTest, InitWithVector) {
    std::vector<int> vec = { 1, 2, 3 };
    Stack s(vec);
    EXPECT_FALSE(s.isEmpty());
    EXPECT_EQ(s.top(), 3);
}

TEST(StackTest, Push) {
    Stack s;
    s.push(1);
    EXPECT_EQ(s.top(), 1);

    s.push(2);
    EXPECT_EQ(s.top(), 2);

    s.push(3);
    EXPECT_EQ(s.top(), 3);
}

TEST(StackTest, Pop) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    s.pop();
    EXPECT_EQ(s.top(), 2);

    s.pop();
    EXPECT_EQ(s.top(), 1);

    s.pop();
    EXPECT_TRUE(s.isEmpty());
}

TEST(StackTest, PopEmpty) {
    Stack s;
    EXPECT_THROW(s.pop(), std::runtime_error);
}

TEST(StackTest, TopEmpty) {
    Stack s;
    EXPECT_THROW(s.top(), std::runtime_error);
}

TEST(StackTest, IsEmpty) {
    Stack s;
    EXPECT_TRUE(s.isEmpty());

    s.push(1);
    EXPECT_FALSE(s.isEmpty());

    s.pop();
    EXPECT_TRUE(s.isEmpty());
}

TEST(StackTest, OstreamOperator) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    std::ostringstream os;
    os << s;
    EXPECT_EQ(os.str(), "3 2 1 ");
}

TEST(StackTest, AddEqual) {
    Stack s1;
    s1.push(1);
    s1.push(2);

    Stack s2;
    s2.push(3);
    s2.push(4);

    s1 += s2;
    std::ostringstream os;
    os << s1;
    EXPECT_EQ(os.str(), "4 3 2 1 ");
}

TEST(StackTest, Add) {
    Stack s1;
    s1.push(1);
    s1.push(2);

    Stack s2;
    s2.push(3);
    s2.push(4);

    Stack s3 = s1 + s2;
    std::ostringstream os;
    os << s3;
    EXPECT_EQ(os.str(), "4 3 2 1 ");
}

TEST(StackTest, AccessOperator) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    EXPECT_EQ(s[0], 1);
    EXPECT_EQ(s[1], 2);
    EXPECT_EQ(s[2], 3);
    EXPECT_THROW(s[3], std::invalid_argument);
}

TEST(StackTest, Equality) {
    Stack s1;
    s1.push(1);
    s1.push(2);

    Stack s2;
    s2.push(1);
    s2.push(2);

    EXPECT_TRUE(s1 == s2);
}

TEST(StackTest, Inequality) {
    Stack s1;
    s1.push(1);
    s1.push(2);

    Stack s2;
    s2.push(2);
    s2.push(1);

    EXPECT_TRUE(s1 != s2);
}

TEST(StackTest, MultiplyEqual) {
    Stack s;
    s.push(1);
    s.push(2);

    s *= 3;
    std::ostringstream os;
    os << s;
    EXPECT_EQ(os.str(), "6 3 ");
}

TEST(StackTest, Multiply) {
    Stack s;
    s.push(1);
    s.push(2);

    Stack s2 = s * 3;
    std::ostringstream os;
    os << s2;
    EXPECT_EQ(os.str(), "6 3 ");
}

TEST(StackTest, DivideEqual) {
    Stack s;
    s.push(6);
    s.push(9);

    s /= 3;
    std::ostringstream os;
    os << s;
    EXPECT_EQ(os.str(), "3 2 ");
}

TEST(StackTest, DivideEqualByZero) {
    Stack s;
    s.push(6);
    s.push(9);

    EXPECT_THROW(s /= 0, std::invalid_argument);
}

TEST(StackTest, Divide) {
    Stack s;
    s.push(6);
    s.push(9);

    Stack s2 = s / 3;
    std::ostringstream os;
    os << s2;
    EXPECT_EQ(os.str(), "3 2 ");
}

TEST(StackTest, DivideByZero) {
    Stack s;
    s.push(6);
    s.push(9);

    EXPECT_THROW(s / 0, std::invalid_argument);
}

TEST(StackTest, Hash) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    size_t hashValue = s.hash();
    EXPECT_NE(hashValue, 0);
}

TEST(StackTest, HashEmptyStack) {
    Stack s;
    EXPECT_EQ(s.hash(), 0);
}

TEST(StackTest, HashSingleElement) {
    Stack s;
    s.push(5);
    size_t hashValue = s.hash();
    EXPECT_NE(hashValue, 0);
    EXPECT_EQ(hashValue, 5);
}

TEST(StackTest, HashMultipleElements) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    size_t hashValue1 = s.hash();

    Stack s2;
    s2.push(3);
    s2.push(2);
    s2.push(1);
    size_t hashValue2 = s2.hash();

    EXPECT_NE(hashValue1, hashValue2);
}

TEST(StackTest, HashConsistency) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    size_t firstHash = s.hash();
    size_t secondHash = s.hash();
    EXPECT_EQ(firstHash, secondHash);
}


TEST(StackTest, HashOrderSensitivity) {
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    Stack s2;
    s2.push(3);
    s2.push(2);
    s2.push(1);
    EXPECT_NE(s1.hash(), s2.hash());
}

TEST(StackTest, HashDifferentForDifferentData) {
    Stack s1;
    s1.push(10);
    s1.push(20);

    Stack s2;
    s2.push(20);
    s2.push(10);

    EXPECT_NE(s1.hash(), s2.hash());
}

TEST(StackTest, PushIncreasesSize) {
    Stack s;
    s.push(1);
    EXPECT_FALSE(s.isEmpty());

    s.push(2);
    EXPECT_EQ(s.top(), 2);
}

TEST(StackTest, PushMultipleElements) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.top(), 3);
}

TEST(StackTest, IsEmptyInitially) {
    Stack s;
    EXPECT_TRUE(s.isEmpty());
}

TEST(StackTest, PopDecreasesSize) {
    Stack s;
    s.push(1);
    s.push(2);
    s.pop();
    EXPECT_EQ(s.top(), 1);

    s.pop();
    EXPECT_TRUE(s.isEmpty());
}

TEST(StackTest, PopFromEmptyStackThrows) {
    Stack s;
    EXPECT_THROW(s.pop(), std::runtime_error);
}

TEST(StackTest, TopReturnsLastElement) {
    Stack s;
    s.push(1);
    s.push(2);
    EXPECT_EQ(s.top(), 2);
    s.pop();
    EXPECT_EQ(s.top(), 1);
}

TEST(StackTest, TopFromEmptyStackThrows) {
    Stack s;
    EXPECT_THROW(s.top(), std::runtime_error);
}

TEST(StackTest, PlusOperator) {
    Stack s1;
    s1.push(1);
    s1.push(2);

    Stack s2;
    s2.push(3);

    Stack s3 = s1 + s2;
    EXPECT_EQ(s3.top(), 3);
}

TEST(StackTest, PlusEqualsOperator) {
    Stack s1;
    s1.push(1);
    s1.push(2);

    Stack s2;
    s2.push(3);

    s1 += s2;
    EXPECT_EQ(s1.top(), 3);
}

TEST(StackTest, SubscriptOperator) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    EXPECT_EQ(s[0], 1);
    EXPECT_EQ(s[1], 2);
    EXPECT_EQ(s[2], 3);
}

TEST(StackTest, SubscriptOperatorThrowsWhenOutOfBounds) {
    Stack s;
    s.push(1);
    s.push(2);

    EXPECT_THROW(s[3], std::invalid_argument);
}

TEST(StackTest, MultiplicationOperator) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    Stack result = s * 2;

    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 4);
    EXPECT_EQ(result[2], 6);
}

TEST(StackTest, DivisionOperator) {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    Stack result = s / 10;

    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 3);
}

TEST(StackTest, DivisionByZeroThrows) {
    Stack s;
    s.push(1);
    s.push(2);

    EXPECT_THROW(s / 0, std::invalid_argument);
}