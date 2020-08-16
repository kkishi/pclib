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

TEST(macros, debug) {
  using std::array;
  using std::map;
  using std::pair;
  using std::set;
  using std::string;
  using std::vector;
  // Just confirm that it doesn't cause compilation err.r
  vector<int> v = {1, 2, 3};
  debug(v);
  vector<int> s = {1, 2, 3};
  debug(s);
  pair<int, double> p = {1, 2.5};
  debug(p);
  map<int, string> m = {{42, "foo"}};
  debug(m);
  array<int, 4> a = {42};
  debug(a);
  map<pair<set<int>, vector<pair<string, double>>>, array<string, 1>> c;
  debug(c);
  debug(v, s, p, m, a, c);
}
