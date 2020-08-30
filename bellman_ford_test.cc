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

  auto [dist, ok] = BellmanFord(g, 0);

  EXPECT_TRUE(ok);
  EXPECT_THAT(dist, ElementsAre(0, 1, 2));
}

TEST(bellman_ford, negative_cycle) {
  Graph<int> g(3);
  g.AddEdge(0, 1, -3);
  g.AddEdge(1, 2, 1);
  g.AddEdge(2, 0, 1);

  auto [_, ok] = BellmanFord(g, 0);

  EXPECT_FALSE(ok);
}

TEST(bellman_ford, negative_noncycle) {
  Graph<int> g(3);
  g.AddEdge(0, 1, -2);
  g.AddEdge(1, 2, 1);
  g.AddEdge(2, 0, 1);

  auto [dist, ok] = BellmanFord(g, 0);

  EXPECT_TRUE(ok);
  EXPECT_THAT(dist, ElementsAre(0, -2, -1));
}
