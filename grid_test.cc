#include "grid.h"

#include "gtest/gtest.h"

TEST(grid, simple) {
  std::vector<std::vector<int>> v = {
      {1, 1, 1},
      {6, 5, 1},
      {1, 1, 1},
  };
  Grid<int> grid(v.size(), v[0].size());
  for (std::size_t i = 0; i < v.size(); ++i) {
    for (std::size_t j = 0; j < v[i].size(); ++j) {
      grid.Set(i, j, v[i][j]);
    }
  }
  std::vector<std::vector<std::optional<int>>> d = grid.Distance(0, 0);
  ASSERT_TRUE(d[2][0]);
  EXPECT_EQ(*d[2][0], 6);
}
