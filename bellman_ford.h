#include <limits>
#include <vector>

#include "graph.h"

template <typename T>
std::pair<std::vector<T>, bool> BellmanFord(const Graph<T>& graph, int start) {
  const std::size_t n = graph.NumVertices();

  T inf = std::numeric_limits<T>::max();
  std::vector<T> dist(n, inf);
  dist[start] = 0;

  for (std::size_t iter = 0; iter < n; ++iter) {
    for (std::size_t i = 0; i < n; ++i) {
      if (dist[i] == inf) continue;
      for (const auto& e : graph.Edges(i)) {
        if (T d = dist[i] + e.weight; dist[e.to] > d) {
          if (iter == n - 1) return {dist, false};
          dist[e.to] = d;
        }
      }
    }
  }
  return {dist, true};
}
