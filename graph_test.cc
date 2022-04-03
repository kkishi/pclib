#include "graph.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(graph, add_edge) {
  Graph g(3);
  g[0].push_back(1);
  g[1].push_back(2);
  EXPECT_TRUE(IsTree(g));
  g[2].push_back(0);
  EXPECT_FALSE(IsTree(g));
}
