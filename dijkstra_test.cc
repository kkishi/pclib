#include "dijkstra.h"

#include <vector>

#include "graph.h"
#include "gtest/gtest.h"

TEST(dijkstra, simple) {
  Graph<int> graph(3);
  graph.AddEdge(0, 2, 3);
  graph.AddEdge(0, 1, 1);
  graph.AddEdge(1, 2, 1);

  Result<int> res = Dijkstra(graph, 0);
  EXPECT_TRUE(res.dist[2]);
  EXPECT_EQ(*res.dist[2], 2);

  std::vector<typename Graph<int>::Edge> p = res.Path(2);
  EXPECT_EQ(p.size(), 2);
  std::vector<typename Graph<int>::Edge> e = {{0, 1, 1}, {1, 2, 1}};
  for (size_t i = 0; i < p.size(); ++i) {
    EXPECT_EQ(p[i].from, e[i].from);
    EXPECT_EQ(p[i].to, e[i].to);
    EXPECT_EQ(p[i].weight, e[i].weight);
  }
}
