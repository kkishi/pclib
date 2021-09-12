#include "pbds.h"

#include "gtest/gtest.h"

TEST(pbds, simple) {
  Set<int> s;
  s.insert(1);
  s.insert(3);
  s.insert(5);
  EXPECT_EQ(s.size(), 3);
  EXPECT_EQ(*s.find_by_order(1), 3);
  s.erase(3);
  EXPECT_EQ(s.size(), 2);
  EXPECT_EQ(*s.find_by_order(1), 5);
}

TEST(pbds, multi) {
  Set<std::pair<int, int>> s;
  s.insert({1, 0});
  s.insert({1, 1});
  s.insert({3, 2});
  s.insert({3, 3});
  s.insert({5, 4});
  s.insert({5, 5});
  EXPECT_EQ(s.size(), 6);
  EXPECT_EQ(s.find_by_order(4)->first, 5);
  s.erase({1, 1});
  EXPECT_EQ(s.size(), 5);
  EXPECT_EQ(s.find_by_order(4)->first, 5);
}
