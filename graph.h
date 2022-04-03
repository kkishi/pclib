#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

#include "fix.h"

using Graph = std::vector<std::vector<int64_t>>;

bool IsTree(const Graph& g) {
  std::vector<bool> visited(g.size());
  return Fix([&](auto rec, int node, int parent) -> bool {
    if (visited[node]) return false;
    visited[node] = true;
    for (int child : g[node]) {
      if (child != parent && !rec(child, node)) {
        return false;
      }
    }
    return true;
  })(0, -1);
}

template <typename T>
using WeightedGraph = std::vector<std::vector<std::pair<int64_t, T>>>;

template <typename T>
bool IsTree(const WeightedGraph<T>& g) {
  std::vector<bool> visited(g.size());
  return Fix([&](auto rec, int node, int parent) -> bool {
    if (visited[node]) return false;
    visited[node] = true;
    for (auto [child, _] : g[node]) {
      if (child != parent && !rec(child, node)) {
        return false;
      }
    }
    return true;
  })(0, -1);
}

#endif  // GRAPH_H_
