#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

#include "fix.h"

using Graph = std::vector<std::vector<int32_t>>;

template <typename T>
using WeightedGraph = std::vector<std::vector<std::pair<int32_t, T>>>;

template <typename T>
bool IsTree(const T& g) {
  std::vector<bool> visited(g.size());
  return Fix([&](auto rec, int node, int parent) -> bool {
    if (visited[node]) return false;
    visited[node] = true;
    for (auto e : g[node]) {
      int child;
      if constexpr (std::is_same<T, Graph>::value) {
        child = e;
      } else {
        child = e.first;
      }
      if (child != parent && !rec(child, node)) {
        return false;
      }
    }
    return true;
  })(0, -1);
}

#endif  // GRAPH_H_
