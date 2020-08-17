#include "binary_search.h"

#include <limits>
#include <vector>

#include "gtest/gtest.h"

TEST(binary_search, find) {
  std::vector<int> v = {-1, 3, 5, 7, 13};
  int i = BinarySearch<int>(0, v.size(), [&](int i) { return v[i] <= 5; });
  EXPECT_EQ(i, 2);
}

TEST(binary_search, large) {
  using ll = long long;
  ll m = std::numeric_limits<ll>::max();
  ll result = BinarySearch<ll>(0, m, [&](ll x) { return x <= m - 42; });
  EXPECT_EQ(result, m - 42);
}
