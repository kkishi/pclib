#include "warshall_floyd.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using std::vector;

TEST(warshall_floyd, simple) {
  // Using the example in the following article:
  // https://en.wikipedia.org/w/index.php?title=Floyd%E2%80%93Warshall_algorithm&oldid=948011949
  const int INF = 1 << 29;
  vector<vector<int>> graph = {
      {0, INF, -2, INF},
      {4, 0, 3, INF},
      {INF, INF, 0, 2},
      {INF, -1, INF, 0},
  };
  WarshallFloyd(graph);
  vector<vector<int>> want = {
      {0, -1, -2, 0},
      {4, 0, 2, 4},
      {5, 1, 0, 2},
      {3, -1, 1, 0},
  };
  EXPECT_THAT(graph, testing::ContainerEq(want));
}
