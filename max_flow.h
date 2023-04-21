#include <atcoder/maxflow>

#include "dassert.h"

class MaxFlow {
  using Cap = int64_t;

 public:
  void Add(int from, int to, Cap cap, Cap min_flow = 0) {
    dassert(0 <= min_flow && min_flow <= cap);
    edges_.emplace_back(from, to, cap, min_flow);
    n_ = std::max(n_, std::max(from, to) + 1);
  }
  Cap Flow(int s, int t) const {
    int n = std::max(n_, std::max(s, t) + 1);
    int S = n, T = n + 1;
    atcoder::mf_graph<Cap> g(n + 2);
    int sum = 0;
    for (auto [from, to, cap, min_flow] : edges_) {
      sum += min_flow;
      g.add_edge(from, to, cap - min_flow);
      g.add_edge(from, T, min_flow);
      g.add_edge(S, to, min_flow);
    }
    g.flow(S, T);
    g.flow(s, T);
    g.flow(S, t);
    for (auto e : g.edges()) {
      if ((e.from == S || e.to == T) && e.cap != e.flow) return -1;
    }
    return g.flow(s, t) + sum;
  }

 private:
  int n_ = 0;  // The number of nodes in the original graph.
  std::vector<std::tuple<int, int, Cap, Cap>> edges_;
};
