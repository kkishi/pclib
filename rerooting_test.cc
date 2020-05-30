#include "rerooting.h"

#include "gtest/gtest.h"
#include "modint.h"

using std::vector;

int Max(int a, int b) { return std::max(a, b); }
int Increment(int v) { return v + 1; }

TEST(rerooting, diameter) {
  vector<vector<int>> edges(3);
  edges[0].push_back(1);
  edges[1].push_back(0);
  edges[0].push_back(2);
  edges[2].push_back(0);

  TreeDP<int, Max, Increment> tdp(edges);
  tdp.DFS(0);
  EXPECT_EQ(tdp.DP()[0][0], 1);
  EXPECT_EQ(tdp.DP()[0][1], 1);

  tdp.Rerooting(0);
  EXPECT_EQ(tdp.Result()[0], 2);
  EXPECT_EQ(tdp.Result()[1], 3);
  EXPECT_EQ(tdp.Result()[2], 3);
}

using mint = ModInt<1000000000 + 7>;

struct DP {
  int size;
  mint cnt;
  mint fact;
};

DP Combine(DP a, DP b) {
  return {a.size + b.size, a.cnt * b.cnt, a.fact * b.fact};
}

DP Calc(DP x) {
  return {x.size + 1, x.cnt / x.fact * mint::factorial(x.size),
          mint::factorial(x.size + 1)};
}

// https://atcoder.jp/contests/abc160/tasks/abc160_f
TEST(rerooting, distributing_integers) {
  vector<vector<int>> edges(5);
  auto add_edge = [&edges](int a, int b) {
    --a, --b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  };
  add_edge(1, 2);
  add_edge(2, 3);
  add_edge(3, 4);
  add_edge(3, 5);

  TreeDP<DP, Combine, Calc> tdp(edges);
  tdp.SetUnit({0, 1, 1});
  tdp.DFS(0);
  tdp.Rerooting(0);

  const vector<DP>& result = tdp.Result();
  EXPECT_EQ(result[0].cnt, 2);
  EXPECT_EQ(result[1].cnt, 8);
  EXPECT_EQ(result[2].cnt, 12);
  EXPECT_EQ(result[3].cnt, 3);
  EXPECT_EQ(result[4].cnt, 3);
}
