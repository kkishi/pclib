#include <vector>

#include "fix.h"
#include "graph.h"

template <typename T>
std::vector<int> DFSOrder(const Graph<T>& g, int root = 0) {
  std::vector<bool> seen(g.NumVertices());
  std::vector<int> order;
  Fix([&](auto rec, int node) -> void {
    if (seen[node]) return;
    seen[node] = true;
    order.push_back(node);
    for (const auto& e : g.Edges(node)) {
      rec(e.to);
    }
  })(root);
  return order;
}
