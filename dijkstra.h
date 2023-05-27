#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

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
Result<T> Dijkstra(const WeightedGraph<T>& graph, int64_t source) {
  const int32_t n = graph.size();

  std::vector<std::optional<T>> dist(n);
  std::vector<std::optional<int64_t>> prev(n);
  dist[source] = 0;

  struct S {
    T dist;
    int64_t node;
    bool operator<(const S& s) const { return dist > s.dist; }
  };
  std::priority_queue<S> que;
  que.push({0, source});

  while (!que.empty()) {
    auto [d, n] = que.top();
    que.pop();
    if (d > *dist[n]) continue;
    for (auto [c, w] : graph[n]) {
      dassert(w >= 0);
      if (!dist[c] || *dist[c] > d + w) {
        dist[c] = d + w;
        prev[c] = n;
        que.push({d + w, c});
      }
    }
  }
  return {dist, prev};
}

#endif  // DIJKSTRA_H_
