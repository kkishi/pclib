#include "lca.h"

#include "graph.h"
#include "gtest/gtest.h"

TEST(lca, small) {
  Graph<int> g(5);
  g.AddEdge(0, 1);
  g.AddEdge(1, 2);
  g.AddEdge(0, 3);
  g.AddEdge(3, 4);
  RootedTree tree(g);
  EXPECT_EQ(tree.LCA(2, 4), 0);
}
