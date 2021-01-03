#include "graph.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::ElementsAre;
using testing::UnorderedElementsAre;

using Edge = Graph<int>::Edge;

bool operator==(const Edge& a, const Edge& b) {
  return a.from == b.from && a.to == b.to && a.weight == b.weight;
}

TEST(graph, add_edge) {
  Graph<int> g(3);
  g.AddEdge(0, 1, 1);
  g.AddEdge(0, 2, 2);
  g.AddEdge(1, 2, 3);
  EXPECT_EQ(g.NumVertices(), 3);
  EXPECT_THAT(g.Edges(0), UnorderedElementsAre(Edge{0, 1, 1}, Edge{0, 2, 2}));
  EXPECT_THAT(g.Edges(1), ElementsAre(Edge{1, 2, 3}));
  EXPECT_EQ(g.Edges(2).size(), 0);
}
