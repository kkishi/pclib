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
    dassert(prev[dest]);
    std::vector<int64_t> v;
    while (dest >= 0) {
      v.push_back(dest);
      dest = *prev[dest];
    }
    std::reverse(v.begin(), v.end());
    return v;
  }
};

template <typename T>
struct DijkstraState {
  T dist;
  int64_t node;
  int64_t prev;
  bool operator<(const DijkstraState& s) const { return dist > s.dist; }
};

template <typename T>
Result<T> Dijkstra(const WeightedGraph<T>& graph, int64_t source) {
  const int32_t n = graph.size();

  std::vector<std::optional<T>> dist(n);
  std::vector<std::optional<int64_t>> prev(n);

  std::priority_queue<DijkstraState<T>> que;
  que.push({0, source, -1});

  while (!que.empty()) {
    auto [d, n, p] = que.top();
    que.pop();
    if (dist[n]) continue;
    dist[n] = d;
    prev[n] = p;
    for (auto [c, w] : graph[n]) {
      dassert(w >= 0);
      que.push({d + w, c, n});
    }
  }
  return {dist, prev};
}
