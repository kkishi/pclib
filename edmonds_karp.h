#include <limits>
#include <queue>
#include <vector>

#include "graph.h"

template <typename T>
T EdmondsKarp(const WeightedGraph<T>& g, int src, int dst) {
  int N = g.size();
  std::vector<std::vector<T>> flow(N, std::vector<T>(N));
  T total = 0;
  while (true) {
    std::queue<std::pair<int, T>> que;
    que.push({src, std::numeric_limits<T>::max()});
    std::vector<int> prev(N, -1);
    while (!que.empty()) {
      auto [u, f] = que.front();
      que.pop();
      if (u == dst) {
        total += f;
        while (u != src) {
          flow[prev[u]][u] += f;
          flow[u][prev[u]] -= f;
          u = prev[u];
        }
        break;
      }
      for (auto [v, weight] : g[u]) {
        if (prev[v] != -1) continue;
        T residue = weight - flow[u][v];
        if (residue == 0) continue;
        prev[v] = u;
        que.push({v, std::min(f, residue)});
      }
    }
    if (prev[dst] == -1) break;
  }
  return total;
}
