#include <tuple>

#include "dassert.h"
#include "dijkstra.h"
#include "graph.h"

template <typename T>
std::tuple<int, int, int> Diameter(const WeightedGraph<T>& g) {
  dassert(g.IsTree());

  auto dist = Dijkstra(g, 0).dist;
  int furthest = -1;
  int u;
  for (size_t i = 0; i < g.size(); ++i) {
    if (furthest < *dist[i]) {
      furthest = *dist[i];
      u = i;
    }
  }
  dist = Dijkstra(g, u).dist;
  furthest = -1;
  int v;
  for (size_t i = 0; i < g.size(); ++i) {
    if (furthest < *dist[i]) {
      furthest = *dist[i];
      v = i;
    }
  }
  return {furthest, u, v};
}
