#include <cassert>
#include <vector>

#include "graph.h"

template <typename T>
class RootedTree {
 public:
  RootedTree(const Graph<T>& graph, int root = 0) : graph_(graph) {
#ifdef DEBUG
    assert(graph.IsTree());
#endif
    const int n = graph.NumVertices();
    int p = 1;
    while ((1 << p) < n) ++p;
    parent_.resize(p);
    for (auto& p : parent_) {
      p.resize(n);
    }
    depth_.resize(n);
    ascending_edge_.resize(n);

    Dfs(root, -1, 0);

    for (int i = 1; i < p; ++i) {
      for (int j = 0; j < n; ++j) {
        int k = parent_[i - 1][j];
        if (k != -1) k = parent_[i - 1][k];
        parent_[i][j] = k;
      }
    }
  }

  int LCA(int u, int v) const {
    if (Depth(u) > Depth(v)) {
      std::swap(u, v);
    }
    for (int i = parent_.size() - 1; i >= 0; --i) {
      if (Depth(v) - (1 << i) >= Depth(u)) {
        v = parent_[i][v];
      }
    }
    if (u == v) {
      return u;
    }
    for (int i = parent_.size() - 1; i >= 0; --i) {
      if (int pu = parent_[i][u], pv = parent_[i][v]; pu != pv) {
        u = pu;
        v = pv;
      }
    }
    return Parent(u);
  }

  int Distance(int i, int j) const {
    return Depth(i) + Depth(j) - 2 * Depth(LCA(i, j));
  }
  int Depth(int i) const { return depth_[i]; }
  int Parent(int i) const { return parent_[0][i]; }
  const Graph<int>::Edge& AscendingEdge(int i) const {
    assert(parent_[0][i] != -1);  // Check that i is not the root.
    return graph_.Edges(i)[ascending_edge_[i]];
  }

 private:
  void Dfs(int node, int parent, int depth) {
    parent_[0][node] = parent;
    depth_[node] = depth;
    const auto& edges = graph_.Edges(node);
    for (size_t i = 0; i < edges.size(); ++i) {
      auto& e = edges[i];
      int child = e.to;
      if (child == parent) {
        ascending_edge_[node] = i;
        continue;
      }
      Dfs(child, node, depth + 1);
    }
  }

  const Graph<T>& graph_;
  std::vector<std::vector<int>> parent_;
  std::vector<int> ascending_edge_;
  std::vector<int> depth_;
};
