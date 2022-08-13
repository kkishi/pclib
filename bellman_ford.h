#include <limits>
#include <vector>

#include "graph.h"

template <typename T>
std::pair<std::vector<std::optional<T>>, bool> BellmanFord(
    const WeightedGraph<T>& graph, int start) {
  const int n = graph.size();

  std::vector<std::optional<T>> dist(n);
  dist[start] = 0;

  for (int iter = 0; iter < n; ++iter) {
    for (int i = 0; i < n; ++i) {
      if (!dist[i]) continue;
      for (auto [j, w] : graph[i]) {
        if (T d = *dist[i] + w; !dist[j] || *dist[j] > d) {
          if (iter == n - 1) return {dist, false};
          dist[j] = d;
        }
      }
    }
  }
  return {dist, true};
}
