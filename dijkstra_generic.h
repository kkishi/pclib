#ifndef DIJKSTRA_GENERIC_H_
#define DIJKSTRA_GENERIC_H_

#include <functional>
#include <map>
#include <queue>

template <typename State, typename Cost>
std::unordered_map<State, Cost> Dijkstra(
    State init,
    std::function<void(State, std::function<void(State, Cost)>)> next) {
  using P = std::pair<Cost, State>;
  std::priority_queue<P, std::vector<P>, std::greater<P>> que;
  std::unordered_map<State, Cost> dist;
  auto push = [&](State s, Cost c) {
    auto [it, ok] = dist.emplace(s, c);
    if (ok || chmin(it->second, c)) que.emplace(c, s);
  };
  push(init, 0);
  while (!que.empty()) {
    auto [c, s] = que.top();
    que.pop();
    if (dist[s] >= c) next(s, [&](State ns, int dc) { push(ns, c + dc); });
  }
  return dist;
}

#endif  // DIJKSTRA_GENERIC_H_
