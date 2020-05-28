#include <map>
#include <optional>
#include <queue>
#include <vector>

using Node = int;
using Cost = int;

struct Edge {
  Node node;
  Cost cost;
};

struct State {
  Node node;
  Cost cost;
  bool operator<(const State& s) const { return cost > s.cost; }
};

// NOTE: This implementation is very limited and is never used for solving
// problems yet.
template <class Graph>
std::optional<Cost> Dijkstra(const Graph& graph, const Node& init,
                             const Node& dest) {
  std::map<Node, Cost> best;
  std::priority_queue<State> que;

  auto push = [&best, &que](const State& there) {
    std::map<Node, Cost>::const_iterator it = best.find(there.node);
    if (it != best.end() && it->second <= there.cost) {
      return;
    }
    best[there.node] = there.cost;
    que.push(there);
  };

  push({init, 0});

  while (!que.empty()) {
    State here = que.top();
    que.pop();
    if (here.node == dest) {
      return here.cost;
    }
    for (const Edge& e : graph.Edges(here.node)) {
      push({e.node, here.cost + e.cost});
    }
  }
  return std::nullopt;
};
