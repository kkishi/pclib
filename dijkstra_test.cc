#include "dijkstra.h"

#include <vector>

#include "graph.h"
#include "gtest/gtest.h"

TEST(dijkstra, simple) {
  WeightedGraph<int> graph = {{{2, 3}, {1, 1}}, {{2, 1}}, {}};

  Result<int> res = Dijkstra(graph, 0);
  EXPECT_TRUE(res.dist[2]);
  EXPECT_EQ(*res.dist[2], 2);

  EXPECT_EQ(res.Path(2), (std::vector<int64_t>{0, 1, 2}));
}
