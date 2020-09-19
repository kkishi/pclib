#include "topological_sort.h"

#include "gtest/gtest.h"

TEST(topological_sort, simple) {
  Graph<int> g(12);
  g.AddEdge(7, 8);
  g.AddEdge(7, 11);
  g.AddEdge(5, 11);
  g.AddEdge(3, 8);
  g.AddEdge(3, 10);
  g.AddEdge(11, 2);
  g.AddEdge(11, 9);
  g.AddEdge(11, 10);
  g.AddEdge(8, 9);

  std::vector<int> v = TopologicalSort(g);

  std::vector<int> index(v.size());
  for (std::size_t i = 0; i < v.size(); ++i) {
    index[v[i]] = i;
  }
  for (int u = 0; u < g.NumVertices(); ++u) {
    for (const auto& e : g.Edges(u)) {
      int v = e.to;
      EXPECT_TRUE(index[u] < index[v]);
    }
  }
}
