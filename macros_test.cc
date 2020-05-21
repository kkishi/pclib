#include "macros.h"

#include <set>
#include <vector>

#include "gtest/gtest.h"

TEST(gcd, simple) {
  std::set<int> s;
  REP(i, 3) s.insert(i);

  std::vector v(ALL(s));
  EXPECT_EQ(v, std::vector({0, 1, 2}));
}
