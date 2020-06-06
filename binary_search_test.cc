#include "binary_search.h"

#include <vector>

#include "gtest/gtest.h"

TEST(binary_search, find) {
  std::vector<int> v = {-1, 3, 5, 7, 13};
  int i = BinarySearch<int>(0, v.size(), [&](int i) { return v[i] <= 5; });
  EXPECT_EQ(i, 2);
}
