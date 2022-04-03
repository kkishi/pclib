#include <limits>
#include <vector>

#include "graph.h"

template <typename T>
std::pair<std::vector<T>, bool> BellmanFord(const WeightedGraph<T>& graph,
                                            int start) {
  const int n = graph.size();

  T inf = std::numeric_limits<T>::max();
  std::vector<T> dist(n, inf);
  dist[start] = 0;

  for (int iter = 0; iter < n; ++iter) {
    for (int i = 0; i < n; ++i) {
      if (dist[i] == inf) continue;
      for (auto [j, w] : graph[i]) {
        if (T d = dist[i] + w; dist[j] > d) {
          if (iter == n - 1) return {dist, false};
          dist[j] = d;
        }
      }
    }
  }
  return {dist, true};
}
