#include <cassert>
#include <functional>
#include <vector>

#include "graph.h"

std::pair<std::vector<int>, bool> TopologicalSort(const Graph& graph) {
  const int n = graph.size();
  std::vector<bool> permanent(n), temporary(n);
  std::vector<int> ret;
  bool ok = true;
  std::function<void(int)> visit = [&](int n) {
    if (permanent[n]) return;
    if (temporary[n]) {
      ok = false;
      return;
    }
    temporary[n] = true;
    for (int c : graph[n]) visit(c);
    temporary[n] = false;
    permanent[n] = true;
    ret.push_back(n);
  };
  for (int i = 0; i < n; ++i) {
    if (!permanent[i]) visit(i);
  }
  reverse(ret.begin(), ret.end());
  return {ret, ok};
}
