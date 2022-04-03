#include "bellman_ford.h"

#include "gmock/gmock.h"
#include "graph.h"
#include "gtest/gtest.h"

using testing::ElementsAre;

TEST(bellman_ford, simple) {
  WeightedGraph<int> g(3);
  g[0].emplace_back(1, 1);
  g[0].emplace_back(2, 2);
  g[1].emplace_back(2, 3);

  auto [dist, ok] = BellmanFord(g, 0);

  EXPECT_TRUE(ok);
  EXPECT_THAT(dist, ElementsAre(0, 1, 2));
}

TEST(bellman_ford, negative_cycle) {
  WeightedGraph<int> g(3);
  g[0].emplace_back(1, -3);
  g[1].emplace_back(2, 1);
  g[2].emplace_back(0, 1);

  auto [_, ok] = BellmanFord(g, 0);

  EXPECT_FALSE(ok);
}

TEST(bellman_ford, negative_noncycle) {
  WeightedGraph<int> g(3);
  g[0].emplace_back(1, -2);
  g[1].emplace_back(2, 1);
  g[2].emplace_back(0, 1);

  auto [dist, ok] = BellmanFord(g, 0);

  EXPECT_TRUE(ok);
  EXPECT_THAT(dist, ElementsAre(0, -2, -1));
}
