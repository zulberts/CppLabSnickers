#include "gtest/gtest.h"
#include "../LoggerLib/OneWayList.h"

TEST(OneWayListTest, Constructor) {
    OneWayList<int> list;
    ASSERT_EQ(list.begin(), list.end());
}

TEST(OneWayListTest, PushFront) {
    OneWayList<int> list;
    list.push_front(10);
    ASSERT_NE(list.begin(), list.end());
    ASSERT_EQ(*list.begin(), 10);

    list.push_front(20);
    auto it = list.begin();
    ASSERT_EQ(*it, 20);
    ++it;
    ASSERT_EQ(*it, 10);
}

TEST(OneWayListTest, Destructor) {
    OneWayList<int>* list = new OneWayList<int>();
    list->push_front(10);
    list->push_front(20);
    delete list;
}

TEST(OneWayListTest, Iterator) {
    OneWayList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    int expected_value = 3;
    for (auto it = list.begin(); it != list.end(); ++it) {
        ASSERT_EQ(*it, expected_value--);
    }
}

TEST(OneWayListTest, IteratorInequality) {
    OneWayList<int> list;
    list.push_front(10);

    ASSERT_TRUE(list.begin() != list.end());
    ASSERT_FALSE(list.end() != list.end());
}

TEST(OneWayListTest, IsEmpty) {
    OneWayList<int> list;
    ASSERT_TRUE(list.isEmpty());
    list.push_front(10);
    ASSERT_FALSE(list.isEmpty());
}

TEST(OneWayListTest, PopFront) {
    OneWayList<int> list;
    list.push_front(10);
    list.pop_front();
    ASSERT_TRUE(list.isEmpty());
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.pop_front();
    EXPECT_FALSE(list.isEmpty());
    list.pop_front();
    list.pop_front();
    EXPECT_TRUE(list.isEmpty());
}

TEST(OneWayListTest, PushBack) {
    OneWayList<int> list;
    list.push_front(10);
    list.push_back(20);
    ASSERT_FALSE(list.isEmpty());
}

TEST(OneWayListTest, PopFrontEmptyList) {
    OneWayList<int> list;
    ASSERT_TRUE(list.isEmpty());
    ASSERT_NO_THROW(list.pop_front());
}
