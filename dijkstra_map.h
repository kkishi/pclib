#ifndef DIJKSTRA_MAP_H_
#define DIJKSTRA_MAP_H_

#include <functional>
#include <map>
#include <queue>

template <typename State, typename Cost>
std::map<State, Cost> Dijkstra(
    State init,
    std::function<void(State, std::function<void(State, Cost)>)> next) {
  using P = std::pair<Cost, State>;
  std::priority_queue<P, std::vector<P>, std::greater<P>> que;
  std::map<State, Cost> dist;
  auto push = [&](State state, Cost cost) {
    auto [it, ok] = dist.emplace(state, cost);
    if (ok || chmin(it->second, cost)) que.emplace(cost, state);
  };
  push(init, 0);
  while (!que.empty()) {
    auto [cost, state] = que.top();
    que.pop();
    if (dist[state] < cost) continue;
    next(state, [&](State next_state, int cost_diff) {
      push(next_state, cost + cost_diff);
    });
  }
  return dist;
}

#endif  // DIJKSTRA_MAP_H_
