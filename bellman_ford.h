#include <vector>

#include "graph.h"

template <typename T>
bool BellmanFord(const Graph<T>& graph, std::vector<T>& dist) {
  int n = graph.NumVertices();
  for (std::size_t i = 0; i < n; ++i) {
    for (const Edge<T>& e : graph.Edges(i)) {
      if (T d = dist[i] + e.weight; dist[e.to] > d) {
        if (i + 1 == n) return false;
        dist[e.to] = d;
      }
    }
  }
  return true;
}
