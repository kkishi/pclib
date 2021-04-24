#include <vector>

#include "graph.h"

template <typename T>
std::vector<int> DFSOrder(const Graph<T>& g, int root) {
  std::vector<bool> seen(g.NumVertices());
  std::vector<int> order;
  auto rec = [&](auto rec, int node) -> void {
    if (seen[node]) return;
    seen[node] = true;
    order.push_back(node);
    for (const auto& e : g.Edges(node)) {
      rec(rec, e.to);
    }
  };
  rec(rec, root);
  return order;
}
