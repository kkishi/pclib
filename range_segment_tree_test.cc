#include "range_segment_tree.h"

#include <numeric>

#include "gtest/gtest.h"

TEST(segment_tree, apply) {
  RangeSegmentTree t = AdditiveSegmentTree<int>(4);
  t.Apply(1, 3, 2);
  EXPECT_EQ(t.Get(2), 2);
  EXPECT_EQ(t.Aggregate(0, 4), 4);
}

TEST(segment_tree, apply_multi) {
  RangeSegmentTree t = AdditiveSegmentTree<int>(10);
  t.Apply(0, 10, 1);
  EXPECT_EQ(t.Get(8), 1);
  t.Apply(5, 10, 2);
  EXPECT_EQ(t.Aggregate(0, 10), 20);
}

TEST(segment_tree, apply_complex) {
  RangeSegmentTree t = AdditiveSegmentTree<int>(3);
  t.Apply(1, 2, 5);
  t.Apply(0, 3, 2);
  t.Apply(1, 2, -4);
  EXPECT_EQ(t.Get(0), 2);
  EXPECT_EQ(t.Get(1), 3);
  EXPECT_EQ(t.Get(2), 2);
  EXPECT_EQ(t.Aggregate(0, 3), 7);
}

TEST(segment_tree, apply_large) {
  RangeSegmentTree t = AdditiveSegmentTree<int>(1000000);
  t.Apply(0, 1000000, 1);
  EXPECT_EQ(t.Get(0), 1);
  EXPECT_EQ(t.Aggregate(0, 1000000), 1000000);
  t.Apply(500000, 1000000, 2);
  EXPECT_EQ(t.Get(500000), 3);
  EXPECT_EQ(t.Aggregate(0, 1000000), 2000000);
  EXPECT_EQ(t.Aggregate(100, 200), 100);
}

TEST(segment_tree, apply_min) {
  RangeSegmentTree t = MinimumSegmentTree<int>(4);

  t.Apply(0, 2, 3);
  t.Apply(2, 4, 4);
  EXPECT_EQ(t.Aggregate(0, 4), 3);

  t.Apply(1, 3, 2);
  EXPECT_EQ(t.Aggregate(0, 4), 2);

  t.Apply(2, 3, 1);
  EXPECT_EQ(t.Aggregate(2, 3), 1);

  // Apply does not overwrite the value.
  t.Apply(2, 3, 2);
  EXPECT_EQ(t.Get(2), 1);
  EXPECT_EQ(t.Aggregate(2, 3), 1);
}
