#include "dijkstra.h"

#include <vector>

#include "gtest/gtest.h"
#include "graph.h"

TEST(dijkstra, simple) {
  Graph<int> graph(3);
  graph.AddEdge(0, 2, 3);
  graph.AddEdge(0, 1, 1);
  graph.AddEdge(1, 2, 1);

  std::vector<int> dist;
  Dijkstra(graph, 0, dist);
  EXPECT_EQ(dist[2], 2);
}
