#include "bit.h"

#include <vector>

#include "gtest/gtest.h"

TEST(bit, find) {
  BIT<int> bit(8);
  for (int i = 0; i < 8; ++i) {
    bit.Add(i, i + 1);
    EXPECT_EQ(bit.Get(i), i + 1);
  }
  EXPECT_EQ(bit.Sum(7), 8 * 9 / 2);
}

TEST(bit, set) {
  BIT<int> bit(10);
  bit.Add(9, 3);
  EXPECT_EQ(bit.Get(9), 3);
  bit.Set(9, -2);
  EXPECT_EQ(bit.Get(9), -2);
}
