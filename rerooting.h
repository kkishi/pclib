#include <functional>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

#include "bidirected_graph.h"

template <typename T, typename U>
class TreeDP {
  using Edge = typename BidirectedGraph<U>::Edge;
  struct Weight {
    Edge* edge;
    T result;
  };
  using MetaEdge = typename BidirectedGraph<Weight>::Edge;

 public:
  TreeDP(const BidirectedGraph<U>& graph, std::function<T(T, T)> op2,
         std::function<T(const Edge&, T)> op1, T identity = T())
      : graph_(graph.NumVertices()), op2_(op2), op1_(op1), identity_(identity) {
    for (int i = 0; i < graph.NumVertices(); ++i) {
      for (const auto& e : graph.Edges(i)) {
        if (e->from > e->to) continue;
        auto [f, b] = graph_.AddEdge(e->from, e->to);
        f.weight.edge = e.get();
        b.weight.edge = e->back;
      }
    }
  }

  void DFS(int root) {
    // Use a stack to avoid potential stack overflows.
    std::stack<std::tuple<MetaEdge*, bool>> s;
    s.emplace(nullptr, true);

    while (!s.empty()) {
      auto [in_edge, enter] = s.top();
      s.pop();

      int node = in_edge ? in_edge->to : root;
      if (enter) {
        s.emplace(in_edge, false);
        for (const auto& e : graph_.Edges(node)) {
          if (e->back != in_edge) {
            s.emplace(e.get(), true);
          }
        }
      } else {
        T t = identity_;
        for (const auto& e : graph_.Edges(node)) {
          if (e->back != in_edge) {
            t = op2_(t, e->weight.result);
          }
        }
        if (in_edge) {
          in_edge->weight.result = op1_(*in_edge->weight.edge, t);
        }
      }
    }
  }

  std::vector<T> Rerooting(int root) {
    std::vector<T> result(graph_.NumVertices());

    std::stack<std::tuple<const MetaEdge*, T>> s;
    s.emplace(nullptr, identity_);

    while (!s.empty()) {
      auto [in_edge, in_result] = s.top();
      s.pop();

      if (in_edge) {
        in_edge->back->weight.result = in_result;
      }

      int node = in_edge ? in_edge->to : root;
      const auto& edges = graph_.Edges(node);

      // lower[i] = op2_(dp[i - 1], op2_(dp[i - 2], ...))
      std::vector<T> lower(edges.size() + 1);
      lower[0] = identity_;
      for (std::size_t i = 0; i < edges.size(); ++i) {
        lower[i + 1] = op2_(lower[i], edges[i]->weight.result);
      }

      // higher[i] = op2_(dp[i], op2_(dp[i + 1], ...))
      std::vector<T> higher(edges.size() + 1);
      higher[edges.size()] = identity_;
      for (std::size_t i = edges.size() - 1; i < edges.size(); --i) {
        higher[i] = op2_(higher[i + 1], edges[i]->weight.result);
      }

      result[node] = higher[0];

      for (std::size_t i = 0; i < edges.size(); ++i) {
        if (const auto& e = edges[i]; e->back != in_edge) {
          s.emplace(e.get(),
                    op1_(*e->back->weight.edge, op2_(lower[i], higher[i + 1])));
        }
      }
    }
    return result;
  }

 private:
  BidirectedGraph<Weight> graph_;

  const std::function<T(T, T)> op2_;
  const std::function<T(const Edge&, T)> op1_;
  const T identity_;
};
