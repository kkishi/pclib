#include "sparse_table.h"

#include "gtest/gtest.h"

TEST(sparse_table, simple) {
  std::vector<int> v = {2, 1, 0, 1, 2, 3};
  SparseTable<int> t(v, [](int a, int b) { return std::min(a, b); });
  int n = v.size();
  for (int l = 0; l < n; ++l) {
    for (int r = l + 1; r <= n; ++r) {
      int x = v[l];
      for (int j = l + 1; j < r; ++j) {
        x = std::min(x, v[j]);
      }
      EXPECT_EQ(t.Get(l, r), x);
    }
  }
}
