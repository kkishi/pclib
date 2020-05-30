#include "dijkstra.h"

#include <vector>

#include "gtest/gtest.h"

class Graph {
 public:
  Graph(int n) : edges_(n) {}
  const std::vector<Edge>& Edges(const Node& node) const {
    return edges_[node];
  }
  void AddEdge(int src, int dst, int cost) {
    edges_[src].push_back({dst, cost});
  }
  std::vector<std::vector<Edge>> edges_;
};

TEST(dijkstra, simple) {
  Graph graph(3);
  graph.AddEdge(0, 2, 3);
  graph.AddEdge(0, 1, 1);
  graph.AddEdge(1, 2, 1);

  std::optional<Cost> c = Dijkstra(graph, 0, 2);
  EXPECT_TRUE(c);
  EXPECT_EQ(*c, 2);
}
