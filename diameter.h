#include <tuple>

#include "dassert.h"
#include "dijkstra.h"
#include "graph.h"

template <typename T>
std::tuple<int, int, int> Diameter(const Graph<T>& g) {
  dassert(g.IsTree());

  auto dist = Dijkstra(g, 0).dist;
  int furthest = -1;
  int u;
  for (int i = 0; i < g.NumVertices(); ++i) {
    if (furthest < *dist[i]) {
      furthest = *dist[i];
      u = i;
    }
  }
  dist = Dijkstra(g, u).dist;
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
