#include <algorithm>
#include <cassert>
#include <optional>
#include <queue>
#include <vector>

#include "graph.h"

template <typename T>
struct Result {
  using Edge = typename Graph<T>::Edge;
  std::vector<std::optional<T>> dist;
  std::vector<std::optional<Edge>> prev;
  std::vector<Edge> Path(int dest) const {
    assert(prev[dest]);
    std::vector<Edge> v;
    for (std::optional<Edge> e = prev[dest]; e; e = prev[e->from]) {
      v.push_back(*e);
    }
    std::reverse(v.begin(), v.end());
    return v;
  }
};

template <typename T>
Result<T> Dijkstra(const Graph<T>& graph, int start) {
  const int n = graph.NumVertices();

  std::vector<std::optional<T>> dist(n);
  std::vector<std::optional<typename Graph<T>::Edge>> prev(n);

  using element = std::pair<T, int>;
  std::priority_queue<element, std::vector<element>, std::greater<>> que;

  dist[start] = 0;
  que.emplace(0, start);

  while (!que.empty()) {
    auto [c, u] = que.top();
    que.pop();
    if (c > dist[u]) continue;
    for (const auto& e : graph.Edges(u)) {
      T d = c + e.weight;
      if (dist[e.to] && *dist[e.to] <= d) continue;
      dist[e.to] = d;
      prev[e.to] = e;
      que.emplace(d, e.to);
    }
  }
  return {dist, prev};
}
