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

TEST(macros, popcount) {
  EXPECT_EQ(popcount(std::numeric_limits<int64_t>::max()), 63);
}

TEST(macros, hasbit) {
  EXPECT_TRUE(hasbit(7, 2));
  EXPECT_FALSE(hasbit(7, 3));
}

TEST(macros, rep) {
  {
    int cnt = 0;
    rep(3)++ cnt;
    EXPECT_EQ(cnt, 3);
  }
  {
    int cnt = 0;
    rep(i, 3)++ cnt;
    EXPECT_EQ(cnt, 3);
  }
  {
    int cnt = 0;
    rep(i, 1, 3)++ cnt;
    EXPECT_EQ(cnt, 2);
  }
  // This test case causes a complication error as expected (used with a type
  // that is not a known integral type).
  /*
  {
    {
      int cnt = 0;
      __int128_t a = numeric_limits<__int128_t>::max() - 1, b = a + 1;
      rep(i, a, b)++ cnt;
      EXPECT_EQ(cnt, 1);
    }
  }
  */
}

TEST(macros, rrep) {
  {
    int cnt = 0;
    rrep(3)++ cnt;
    EXPECT_EQ(cnt, 3);
  }
  {
    int cnt = 0;
    rrep(i, 3)++ cnt;
    EXPECT_EQ(cnt, 3);
  }
  {
    int cnt = 0;
    rrep(i, 1, 3)++ cnt;
    EXPECT_EQ(cnt, 2);
  }
  {
    int cnt = 0;
    rrep(i, uint(0), uint(1))++ cnt;
    EXPECT_EQ(cnt, 1);
  }
}

TEST(macros, each) {
  {
    std::vector<int> v{1, 2, 3};
    int sum = 0;
    each(vi, v) sum += vi;
    EXPECT_EQ(sum, 6);
  }
  {
    std::map<int, int> m{{1, 2}, {3, 4}};
    int sum = 0;
    each(k, v, m) sum += k * v;
    EXPECT_EQ(sum, 14);
  }
}

// Floored division
// https://en.wikipedia.org/wiki/Modulo_operation
TEST(macros, div) {
  EXPECT_EQ(div_floor(10, 3), 3);
  EXPECT_EQ(div_floor(9, 3), 3);

  EXPECT_EQ(div_floor(-10, 3), -4);
  EXPECT_EQ(div_floor(-9, 3), -3);

  EXPECT_EQ(div_floor(10, -3), -4);
  EXPECT_EQ(div_floor(9, -3), -3);

  EXPECT_EQ(div_ceil(10, 3), 4);
  EXPECT_EQ(div_ceil(9, 3), 3);

  EXPECT_EQ(div_ceil(-10, 3), -3);
  EXPECT_EQ(div_ceil(-9, 3), -3);

  EXPECT_EQ(div_ceil(10, -3), -3);
  EXPECT_EQ(div_ceil(9, -3), -3);
}
