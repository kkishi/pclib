#include "int_sqrt.h"

#include "gtest/gtest.h"

TEST(int_sqrt, small) {
  std::vector<std::pair<int, int>> tests{{0, 0}, {1, 1}, {2, 1}, {3, 1},
                                         {4, 2}, {5, 2}, {6, 2}, {7, 2},
                                         {8, 2}, {9, 3}, {10, 3}};
  for (auto [x, y] : tests) {
    EXPECT_EQ(IntSqrt<int>(x), y);
  }
}

TEST(int_sqrt, large) {
  int64_t x = 12345;
  EXPECT_EQ(IntSqrt<int64_t>(x * x + 42), x);
  EXPECT_EQ(IntSqrt<int32_t>(2147483647), 46340);
  EXPECT_EQ(IntSqrt<int64_t>(9223372036854775807), 3037000499);
  EXPECT_EQ(IntSqrt<uint64_t>(18446744073709551615u), 4294967295);
}

TEST(int_sqrt, invalid) { EXPECT_DEATH(IntSqrt<int>(-1), ""); }
