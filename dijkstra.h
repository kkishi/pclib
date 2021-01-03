#include <optional>
#include <queue>
#include <vector>

#include "graph.h"

template <typename T>
std::vector<std::optional<T>> Dijkstra(const Graph<T>& graph, int start) {
  const int n = graph.NumVertices();

  std::vector<std::optional<T>> dist(n);

  using element = std::pair<T, int>;
  std::priority_queue<element, std::vector<element>, std::greater<>> que;

  auto push = [&dist, &que](int u, T c) {
    if (dist[u] && *dist[u] <= c) return;
    dist[u] = c;
    que.push({c, u});
  };

  push(start, 0);

  while (!que.empty()) {
    auto [c, u] = que.top();
    que.pop();
    for (const auto& e : graph.Edges(u)) {
      push(e.to, c + e.weight);
    }
  }

  return dist;
}
