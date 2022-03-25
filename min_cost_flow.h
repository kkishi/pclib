#include <atcoder/mincostflow>

class MinCostFlow {
  using Cap = int64_t;
  using Cost = int64_t;

 public:
  void Add(int from, int to, Cap cap, Cost cost, Cap min_flow = 0) {
    assert(0 <= min_flow && min_flow <= cap);
    assert(cost >= 0 || min_flow == 0);  // Not supported yet.
    edges_.emplace_back(from, to, cap, cost, min_flow);
    n_ = std::max(n_, std::max(from, to) + 1);
  }
  std::pair<Cap, Cost> Flow(int s, int t) const {
    int S = n_, T = n_ + 1;
    atcoder::mcf_graph<Cap, Cost> g(n_ + 2);
    g.add_edge(t, s, std::numeric_limits<Cap>::max(), 0);
    Cost sum = 0;
    for (auto [from, to, cap, cost, min_flow] : edges_) {
      if (cost < 0) {
        sum += cap * cost;
        g.add_edge(to, from, cap, -cost);
        g.add_edge(S, to, cap, 0);
        g.add_edge(from, T, cap, 0);
      } else if (min_flow > 0) {
        assert(min_flow <= cap);
        g.add_edge(from, to, cap - min_flow, cost);
        g.add_edge(S, to, min_flow, 0);
        g.add_edge(from, T, min_flow, 0);
      } else {
        g.add_edge(from, to, cap, cost);
      }
    }
    auto fc = g.flow(S, T);
    fc.second += sum;
    return fc;
  }

 private:
  int n_ = 0;
  std::vector<std::tuple<int, int, Cap, Cost, Cap>> edges_;
};
