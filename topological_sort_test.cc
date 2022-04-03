#include "topological_sort.h"

#include "gtest/gtest.h"

TEST(topological_sort, simple) {
  Graph g(12);
  g[7].push_back(8);
  g[7].push_back(11);
  g[5].push_back(11);
  g[3].push_back(8);
  g[3].push_back(10);
  g[11].push_back(2);
  g[11].push_back(9);
  g[11].push_back(10);
  g[8].push_back(9);

  auto [v, ok] = TopologicalSort(g);
  EXPECT_TRUE(ok);

  std::vector<int> index(v.size());
  for (std::size_t i = 0; i < v.size(); ++i) {
    index[v[i]] = i;
  }
  for (int u = 0; u < g.size(); ++u) {
    for (int v : g[u]) {
      EXPECT_LT(index[u], index[v]);
    }
  }
}

TEST(topological_sort, loop) {
  Graph g = {{1}, {2}, {0}};

  auto [v, ok] = TopologicalSort(g);
  EXPECT_FALSE(ok);
}
