#include "macros.h"

#include <set>
#include <vector>

#include "gtest/gtest.h"

using std::array;
using std::is_same;
using std::map;
using std::numeric_limits;
using std::optional;
using std::pair;
using std::set;
using std::string;
using std::tuple;
using std::vector;

TEST(macros, simple) {
  set<int> s;
  rep(i, 3) s.insert(i);

  vector v(all(s));
  EXPECT_EQ(v, vector({0, 1, 2}));
}

TEST(macros, V) {
  V<int> v = {1};
  VV<int> vv(2, V<int>(2, 42));
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(vv[1][1], 42);
}

TEST(macros, sfinae) {
  // Raw pointers and optionals are dereferenceable.
  EXPECT_TRUE(is_dereferenceable<int*>::value);
  EXPECT_TRUE(is_dereferenceable<optional<int>>::value);
  EXPECT_FALSE(is_dereferenceable<int>::value);
  EXPECT_FALSE((is_dereferenceable<tuple<int, int>>::value));

  // Container like things are iterable. One caveat is that string is iterable,
  // but we don't generally want to treat it as such.
  EXPECT_TRUE(is_iterable<vector<int>>::value);
  EXPECT_TRUE((is_iterable<array<int, 1000000>>::value));
  EXPECT_FALSE((is_iterable<tuple<int, int, int>>::value));
  EXPECT_TRUE(is_iterable<string>::value);

  // Tuple like things are applicable (can work with std::apply).
  EXPECT_TRUE((is_applicable<pair<int, int>>::value));
  EXPECT_TRUE((is_applicable<tuple<int, int>>::value));
  EXPECT_FALSE(is_applicable<vector<int>>::value);
  EXPECT_TRUE((is_applicable<array<int, 1000000>>::value));
}

TEST(macros, debug) {
  using std::array;
  using std::map;
  using std::optional;
  using std::pair;
  using std::set;
  using std::string;
  using std::tuple;
  using std::vector;

  // Just confirm that it doesn't cause compilation error.
  debug(int{42});
  debug((array<int, 4>{42}));
  debug((map<int, string>{{42, "foo"}}));
  debug(optional<int>{});
  debug(optional<int>{42});
  debug((pair<int, double>{1, 2.5}));
  debug((set<int>{1, 2, 3}));
  debug(string{"str"});
  debug((tuple<int, int, int>{4, 5, 6}));
  debug((vector<int>{1, 2, 3}));
  int i = 42;
  debug(&i);
  debug((int*){nullptr});
  debug((map<pair<set<int>, vector<pair<string, double>>>,
             array<tuple<string>, 1>>{}));
}

TEST(macros, popcount) {
  EXPECT_EQ(popcount(numeric_limits<int64_t>::max()), 63);
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
    vector<int> v{1, 2, 3};
    int sum = 0;
    each(vi, v) sum += vi;
    EXPECT_EQ(sum, 6);
  }
  {
    map<int, int> m{{1, 2}, {3, 4}};
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
