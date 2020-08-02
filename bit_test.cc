#include "bit.h"

#include <vector>

#include "gtest/gtest.h"

TEST(bit, find) {
  BIT<int> bit(8);
  for (int i = 1; i <= 8; ++i) {
    bit.Add(i, i);
    EXPECT_EQ(bit.Get(i), i);
  }
  EXPECT_EQ(bit.Sum(8), 8 * 9 / 2);
}
