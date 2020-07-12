#include "dijkstra.h"

#include <vector>

#include "graph.h"
#include "gtest/gtest.h"

TEST(dijkstra, simple) {
  Graph<int> graph(3);
  graph.AddEdge(0, 2, 3);
  graph.AddEdge(0, 1, 1);
  graph.AddEdge(1, 2, 1);

  std::vector<std::optional<int>> dist = Dijkstra(graph, 0);
  EXPECT_TRUE(dist[2]);
  EXPECT_EQ(*dist[2], 2);
}
