#include "dijkstra.h"

#include <vector>

#include "gmock/gmock.h"
#include "graph.h"
#include "gtest/gtest.h"

using ::testing::ElementsAre;

TEST(dijkstra, simple) {
  WeightedGraph<int> graph = {{{2, 3}, {1, 1}}, {{2, 1}}, {}};

  Result<int> res = Dijkstra(graph, 0);
  EXPECT_TRUE(res.dist[2]);
  EXPECT_EQ(*res.dist[2], 2);
  EXPECT_THAT(res.Path(2), ElementsAre(0, 1, 2));
}
