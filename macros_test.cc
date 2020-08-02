#include "macros.h"

#include <set>
#include <vector>

#include "gtest/gtest.h"

TEST(macros, simple) {
  std::set<int> s;
  rep(i, 3) s.insert(i);

  std::vector v(all(s));
  EXPECT_EQ(v, std::vector({0, 1, 2}));
}

TEST(macros, V) {
  V<int> v = {1};
  VV<int> vv(2, V<int>(2, 42));
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(vv[1][1], 42);
}
