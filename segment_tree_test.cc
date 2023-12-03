#include "segment_tree.h"

#include <numeric>

#include "gtest/gtest.h"

TEST(segment_tree, simple) {
  auto add = [](int a, int b) { return a + b; };
  SegmentTree<int> t(3, add);
  t.Set(0, 1);
  t.Set(1, 2);
  t.Set(2, 4);
  EXPECT_EQ(t.Aggregate(0, 3), 7);

  t.Set(1, 3);
  EXPECT_EQ(t.Aggregate(0, 3), 8);
}

// https://atcoder.jp/contests/abc125/tasks/abc125_c
TEST(segment_tree, gcd) {
  auto gcd = [](int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return std::gcd(a, b);
  };
  SegmentTree<int> t(3, gcd);
  t.Set(0, 7);
  t.Set(1, 6);
  t.Set(2, 8);
  EXPECT_EQ(t.Aggregate(0, 1), 7);
  EXPECT_EQ(t.Aggregate(1, 2), 6);
  EXPECT_EQ(t.Aggregate(2, 3), 8);
  EXPECT_EQ(t.Aggregate(0, 2), 1);
  EXPECT_EQ(t.Aggregate(1, 3), 2);
}

TEST(segment_tree, min) {
  auto min = [](int a, int b) { return std::min(a, b); };
  SegmentTree<int> t(4, min, std::numeric_limits<int>::max());
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

TEST(segment_tree, application_order) {
  using std::string;
  auto concat = [](string a, string b) { return a + b; };
  SegmentTree<string> t(8, concat);
  string s = "abcdefgh";
  for (int i = 0; i < 8; ++i) t.Set(i, string(1, s[i]));
  for (int l = 0; l < 8; ++l) {
    for (int r = l + 1; r <= 8; ++r) {
      EXPECT_EQ(t.Aggregate(l, r), s.substr(l, r - l));
    }
  }
}
