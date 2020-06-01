#include "segment_tree.h"

#include <numeric>

#include "gtest/gtest.h"

auto add = [](int a, int b) -> int { return a + b; };

TEST(segment_tree, simple) {
  SegmentTree<int> t(3, add);
  t.Set(0, 1);
  t.Set(1, 2);
  t.Set(2, 4);
  EXPECT_EQ(t.Aggregate(0, 3), 7);

  t.Set(1, 3);
  EXPECT_EQ(t.Aggregate(0, 3), 8);
}

int Gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return std::gcd(a, b);
}

// https://atcoder.jp/contests/abc125/tasks/abc125_c
TEST(segment_tree, gcd) {
  SegmentTree<int> t(3, Gcd);
  t.Set(0, 7);
  t.Set(1, 6);
  t.Set(2, 8);
  EXPECT_EQ(t.Aggregate(0, 1), 7);
  EXPECT_EQ(t.Aggregate(1, 2), 6);
  EXPECT_EQ(t.Aggregate(2, 3), 8);
  EXPECT_EQ(t.Aggregate(0, 2), 1);
  EXPECT_EQ(t.Aggregate(1, 3), 2);
}

int Min(int a, int b) { return std::min(a, b); }

const int kInf = 1000000000;

TEST(segment_tree, min) {
  SegmentTree<int> t(4, Min, kInf);
  t.Set(0, 3);
  t.Set(1, 2);
  t.Set(2, 4);
  t.Set(3, 1);

  EXPECT_EQ(t.Get(0), 3);
  EXPECT_EQ(t.Get(1), 2);
  EXPECT_EQ(t.Get(2), 4);
  EXPECT_EQ(t.Get(3), 1);
  EXPECT_EQ(t.Aggregate(0, 1), 3);
  EXPECT_EQ(t.Aggregate(1, 2), 2);
  EXPECT_EQ(t.Aggregate(2, 3), 4);
  EXPECT_EQ(t.Aggregate(3, 4), 1);
  EXPECT_EQ(t.Aggregate(0, 2), 2);
  EXPECT_EQ(t.Aggregate(1, 3), 2);
  EXPECT_EQ(t.Aggregate(2, 4), 1);
  EXPECT_EQ(t.Aggregate(0, 3), 2);
  EXPECT_EQ(t.Aggregate(1, 4), 1);
  EXPECT_EQ(t.Aggregate(0, 4), 1);
}

auto mul = [](int a, int size) -> int { return a * size; };

TEST(segment_tree, apply) {
  SegmentTree<int> t(4, add, 0, mul);
  t.Apply(1, 3, 2);
  EXPECT_EQ(t.Get(2), 2);
  EXPECT_EQ(t.Aggregate(0, 4), 4);
}

TEST(segment_tree, apply_multi) {
  SegmentTree<int> t(10, add, 0, mul);
  t.Apply(0, 10, 1);
  EXPECT_EQ(t.Get(8), 1);
  t.Apply(5, 10, 2);
  EXPECT_EQ(t.Aggregate(0, 10), 20);
}

TEST(segment_tree, apply_large) {
  SegmentTree<int> t(1000000, add, 0, mul);
  t.Apply(0, 1000000, 1);
  EXPECT_EQ(t.Get(0), 1);
  EXPECT_EQ(t.Aggregate(0, 1000000), 1000000);
  t.Apply(500000, 1000000, 2);
  EXPECT_EQ(t.Get(500000), 3);
  EXPECT_EQ(t.Aggregate(0, 1000000), 2000000);
  EXPECT_EQ(t.Aggregate(100, 200), 100);
}
