#include "strongly_connected_component.h"

#include "gmock/gmock.h"
#include "graph.h"
#include "gtest/gtest.h"

using std::vector;
using testing::UnorderedElementsAre;

TEST(strongly_connected_component, simple) {
  // Using the example in the following article:
  // https://en.wikipedia.org/w/index.php?title=Strongly_connected_component&oldid=955750171
  int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, h = 7;
  vector<vector<int>> graph = {
      {b}, {c, e, f}, {d, g}, {c, h}, {a, f}, {g}, {f}, {d, g},
  };

  Graph<int> grp(graph.size());
  for (std::size_t u = 0; u < graph.size(); ++u) {
    for (int v : graph[u]) {
      grp.AddEdge(u, v);
    }
  }
  vector<vector<int>> sccs = StronglyConnectedComponents(grp);

  EXPECT_EQ(sccs.size(), 3);
  EXPECT_THAT(sccs, UnorderedElementsAre(UnorderedElementsAre(a, b, e),
                                         UnorderedElementsAre(c, d, h),
                                         UnorderedElementsAre(f, g)));
}
