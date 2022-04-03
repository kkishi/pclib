#include "edmonds_karp.h"

#include "gtest/gtest.h"

TEST(edmonds_karp, simple) {
  // https://commons.wikimedia.org/wiki/File:Min_cut.png
  int o = 0, p = 1, q = 2, r = 3, s = 4, t = 5;
  WeightedGraph<int> g(t + 1);
  auto add = [&g](int u, int v, int w) {
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, 0);
  };
  add(s, o, 3);
  add(s, p, 3);
  add(o, p, 2);
  add(o, q, 3);
  add(p, r, 2);
  add(q, r, 4);
  add(q, t, 2);
  add(r, t, 3);
  EXPECT_EQ(EdmondsKarp(g, s, t), 5);
}
