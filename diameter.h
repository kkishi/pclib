#include <tuple>

#include "dijkstra.h"
#include "graph.h"

template <typename T>
std::tuple<int, int, int> Diameter(const Graph<T>& g) {
  auto dist = Dijkstra(g, 0);
  int furthest = -1;
  int u;
  for (int i = 0; i < g.NumVertices(); ++i) {
    if (furthest < *dist[i]) {
      furthest = *dist[i];
      u = i;
    }
  }
  dist = Dijkstra(g, u);
  furthest = -1;
  int v;
  for (int i = 0; i < g.NumVertices(); ++i) {
    if (furthest < *dist[i]) {
      furthest = *dist[i];
      v = i;
    }
  }
  return {furthest, u, v};
}
