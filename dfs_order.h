#include <vector>

#include "fix.h"
#include "graph.h"

std::vector<int64_t> DFSOrder(const Graph& g, int root = 0) {
  std::vector<bool> seen(g.size());
  std::vector<int64_t> order;
  Fix([&](auto rec, int node) -> void {
    if (seen[node]) return;
    seen[node] = true;
    order.push_back(node);
    for (int child : g[node]) {
      rec(child);
    }
  })(root);
  return order;
}
