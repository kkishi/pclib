#include <cassert>
#include <functional>
#include <vector>

#include "graph.h"

template <typename T>
std::vector<int> TopologicalSort(const Graph<T>& graph) {
  const int n = graph.NumVertices();
  std::vector<bool> permanent(n), temporary(n);
  std::vector<int> ret;
  std::function<void(int)> visit = [&](int n) {
    if (permanent[n]) return;
    assert(!temporary[n]);
    temporary[n] = true;
    for (const auto& e : graph.Edges(n)) visit(e.to);
    temporary[n] = false;
    permanent[n] = true;
    ret.push_back(n);
  };
  for (int i = 0; i < n; ++i) {
    if (!permanent[i]) visit(i);
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
