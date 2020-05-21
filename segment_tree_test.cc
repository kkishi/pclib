#include "segment_tree.h"

#include "gtest/gtest.h"

TEST(segment_tree, simple) {
  SegmentTree t(3);
  t.Add(0, 1);
  t.Add(1, 2);
  t.Add(2, 4);
  EXPECT_EQ(t.Sum(0, 3), 7);
}
