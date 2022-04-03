#include "dfs_order.h"

#include "gtest/gtest.h"

TEST(dfs_order, simple) {
  Graph g = {{1, 2}, {3}, {}, {}};
  EXPECT_EQ(DFSOrder(g), (std::vector<int64_t>{0, 1, 3, 2}));
}
