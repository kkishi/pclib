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

TEST(macros, sfinae) {
  // Raw pointers and optionals are dereferenceable.
  EXPECT_TRUE(is_dereferenceable<int*>::value);
  EXPECT_TRUE(is_dereferenceable<std::optional<int>>::value);
  EXPECT_FALSE(is_dereferenceable<int>::value);
  EXPECT_FALSE((is_dereferenceable<std::tuple<int, int>>::value));

  // Container like things are iterable. One caveat is that string is iterable,
  // but we don't generally want to treat it as such.
  EXPECT_TRUE(is_iterable<std::vector<int>>::value);
  EXPECT_TRUE((is_iterable<std::array<int, 1000000>>::value));
  EXPECT_FALSE((is_iterable<std::tuple<int, int, int>>::value));
  EXPECT_FALSE(is_iterable<std::string>::value);

  // Tuple like things are applicable (can work with std::apply).
  EXPECT_TRUE((is_applicable<std::pair<int, int>>::value));
  EXPECT_TRUE((is_applicable<std::tuple<int, int>>::value));
  EXPECT_FALSE(is_applicable<std::vector<int>>::value);
  EXPECT_TRUE((is_applicable<std::array<int, 1000000>>::value));
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
  // Just confirm that it doesn't cause compilation err.r
  vector<int> v = {1, 2, 3};
  debug(v);
  vector<int> s = {1, 2, 3};
  debug(s);
  pair<int, double> p = {1, 2.5};
  debug(p);
  tuple<int, int, int> t = {4, 5, 6};
  debug(t);
  map<int, string> m = {{42, "foo"}};
  debug(m);
  array<int, 4> a = {42};
  debug(a);
  int* ip = &v[0];
  debug(ip);
  optional<int> oi;
  debug(oi);
  oi = 42;
  debug(oi);
  map<pair<set<int>, vector<pair<string, double>>>, array<tuple<string>, 1>> c;
  debug(c);
  debug(v, s, p, m, a, c);
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
  {
    {
      int cnt = 0;
      __int128_t a = std::numeric_limits<__int128_t>::max() - 1, b = a + 1;
      rep(i, a, b)++ cnt;
      EXPECT_EQ(cnt, 1);
    }
  }
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
