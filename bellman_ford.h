#include <limits>
#include <vector>

#include "graph.h"

template <typename T>
bool BellmanFord(const Graph<T>& graph, int start, std::vector<T>& dist) {
  std::size_t n = graph.NumVertices();

  dist.resize(n);
  T inf = std::numeric_limits<T>::max();
  fill(dist.begin(), dist.end(), inf);
  dist[start] = 0;

  for (std::size_t iter = 0; iter < n; ++iter) {
    for (std::size_t i = 0; i < n; ++i) {
      if (dist[i] == inf) continue;
      for (const Edge<T>& e : graph.Edges(i)) {
        if (T d = dist[i] + e.weight; dist[e.to] > d) {
          if (iter == n - 1) return false;
          dist[e.to] = d;
        }
      }
    }
  }
  return true;
}
