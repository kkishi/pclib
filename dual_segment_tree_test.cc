#include "dual_segment_tree.h"

#include <numeric>

#include "gtest/gtest.h"

TEST(dual_segment_tree, simple) {
  DualSegmentTree<int> t(4, [](int a, int b) { return a + b; });
  t.Update(0, 3, 1);
  t.Update(2, 4, 2);
  EXPECT_EQ(t.Get(0), 1);
  EXPECT_EQ(t.Get(1), 1);
  EXPECT_EQ(t.Get(2), 3);
  EXPECT_EQ(t.Get(3), 2);
}
