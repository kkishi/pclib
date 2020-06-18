#include <map>
#include <optional>
#include <queue>
#include <vector>

#include "graph.h"

template <typename T>
void Dijkstra(const Graph<T>& graph, int start, std::vector<T>& dist) {
  int n = graph.NumVertices();

  dist.resize(n);
  T inf = std::numeric_limits<T>::max();
  fill(dist.begin(), dist.end(), inf);

  using element = std::pair<T, int>;
  std::priority_queue<element, std::vector<element>, std::greater<>> que;

  auto push = [&](int u, int c) {
    if (dist[u] <= c) return;
    dist[u] = c;
    que.push({c, u});
  };

  push(start, 0);

  while (!que.empty()) {
    auto [c, u] = que.top();
    que.pop();
    for (const Edge<T>& e : graph.Edges(u)) {
      push(e.to, c + e.weight);
    }
  }
}
