#include <algorithm>
#include <optional>
#include <queue>
#include <vector>

#include "dassert.h"
#include "graph.h"

template <typename T>
struct Result {
  std::vector<std::optional<T>> dist;
  std::vector<std::optional<int64_t>> prev;
  std::vector<int64_t> Path(int64_t dest) const {
    std::vector<int64_t> v;
    while (true) {
      v.push_back(dest);
      if (!prev[dest]) break;
      dest = *prev[dest];
    }
    std::reverse(v.begin(), v.end());
    return v;
  }
};

template <typename T>
Result<T> Dijkstra(const WeightedGraph<T>& graph, int start) {
  const int n = graph.size();

  std::vector<std::optional<T>> dist(n);
  std::vector<std::optional<int64_t>> prev(n);

  using element = std::pair<T, int>;
  std::priority_queue<element, std::vector<element>, std::greater<>> que;

  dist[start] = 0;
  que.emplace(0, start);

  while (!que.empty()) {
    auto [c, u] = que.top();
    que.pop();
    if (c > dist[u]) continue;
    for (auto [v, w] : graph[u]) {
      T d = c + w;
      if (dist[v] && *dist[v] <= d) continue;
      dist[v] = d;
      prev[v] = u;
      que.emplace(d, v);
    }
  }
  return {dist, prev};
}
