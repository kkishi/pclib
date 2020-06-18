#include "bellman_ford.h"

#include "gmock/gmock.h"
#include "graph.h"
#include "gtest/gtest.h"

using testing::ElementsAre;

TEST(bellman_ford, simple) {
  Graph<int> g(3);
  g.AddEdge(0, 1, 1);
  g.AddEdge(0, 2, 2);
  g.AddEdge(1, 2, 3);

  std::vector<int> dist;

  EXPECT_TRUE(BellmanFord(g, 0, dist));
  EXPECT_THAT(dist, ElementsAre(0, 1, 2));
}

TEST(bellman_ford, negative_cycle) {
  Graph<int> g(3);
  g.AddEdge(0, 1, -3);
  g.AddEdge(1, 2, 1);
  g.AddEdge(2, 0, 1);

  std::vector<int> dist;

  EXPECT_FALSE(BellmanFord(g, 0, dist));
}

TEST(bellman_ford, negative_noncycle) {
  Graph<int> g(3);
  g.AddEdge(0, 1, -2);
  g.AddEdge(1, 2, 1);
  g.AddEdge(2, 0, 1);

  std::vector<int> dist;

  EXPECT_TRUE(BellmanFord(g, 0, dist));
  EXPECT_THAT(dist, ElementsAre(0, -2, -1));
}
