#include "bidirected_graph.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::ElementsAre;
using testing::Pointee;

using Edge = BidirectedGraph<int>::Edge;

bool operator==(const Edge& a, const Edge& b) {
  return a.from == b.from && a.to == b.to && a.weight == b.weight;
}

TEST(bidirected_graph, add_edge) {
  BidirectedGraph<int> g(2);
  EXPECT_EQ(g.NumVertices(), 2);

  auto [f, b] = g.AddEdge(0, 1);
  f.weight = 2;
  b.weight = 3;
  EXPECT_THAT(g.Edges(0), ElementsAre(Pointee(Edge{0, 1, 2})));
  EXPECT_THAT(g.Edges(1), ElementsAre(Pointee(Edge{1, 0, 3})));
}
