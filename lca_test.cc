#include "lca.h"

#include "graph.h"
#include "gtest/gtest.h"

TEST(lca, small) {
  Graph g = {{1, 3}, {2}, {}, {4}, {}};
  RootedTree tree(g);
  EXPECT_EQ(tree.LCA(2, 4), 0);
}
