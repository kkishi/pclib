#include "rerooting.h"

#include "gtest/gtest.h"
#include "modint.h"

using std::vector;

TEST(rerooting, diameter) {
  BidirectedGraph<int> g(3);
  g.AddEdge(0, 1, 1);
  g.AddEdge(0, 2, 2);

  TreeDP<int, int> tdp(
      g, [](int a, int b) { return std::max(a, b); },
      [](const auto& e, int v) { return e.weight + v; });
  tdp.DFS(0);
  vector<int> result = tdp.Rerooting(0);
  EXPECT_EQ(result[0], 2);
  EXPECT_EQ(result[1], 3);
  EXPECT_EQ(result[2], 3);
}

using mint = ModInt<>;

struct DP {
  int size;
  mint cnt;
  mint fact;
};

DP Combine(DP a, DP b) {
  return {a.size + b.size, a.cnt * b.cnt, a.fact * b.fact};
}

DP Calc(DP x) {
  return {x.size + 1, x.cnt / x.fact * mint::Fact(x.size),
          mint::Fact(x.size + 1)};
}

// https://atcoder.jp/contests/abc160/tasks/abc160_f
TEST(rerooting, distributing_integers) {
  BidirectedGraph<int> g(5);
  auto add_edge = [&g](int a, int b) { g.AddEdge(a - 1, b - 1); };
  add_edge(1, 2);
  add_edge(2, 3);
  add_edge(3, 4);
  add_edge(3, 5);

  TreeDP<DP, int> tdp(g, Combine, [](const auto&, DP x) { return Calc(x); },
                      {0, 1, 1});
  tdp.DFS(0);
  vector<DP> result = tdp.Rerooting(0);

  EXPECT_EQ(Calc(result[0]).cnt, 2);
  EXPECT_EQ(Calc(result[1]).cnt, 8);
  EXPECT_EQ(Calc(result[2]).cnt, 12);
  EXPECT_EQ(Calc(result[3]).cnt, 3);
  EXPECT_EQ(Calc(result[4]).cnt, 3);
}
