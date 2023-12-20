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

TEST(dual_segment_tree, application_order) {
  using std::string;
  auto concat = [](string f, string g) { return g + f; };
  DualSegmentTree<string> t(8, concat);
  string s = "abcdefgh";
  for (int i = 0; i < 8; ++i) t.Update(i, 8, string(1, s[i]));
  for (int i = 0; i < 8; ++i) EXPECT_EQ(t.Get(i), s.substr(0, i + 1));
}
