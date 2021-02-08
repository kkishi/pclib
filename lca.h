#include <vector>

#include "graph.h"

template <typename T>
class LCA {
 public:
  LCA(const Graph<T>& graph, int root = 0) : graph_(graph) {
    const int n = graph.NumVertices();

    int p = 0;
    int two = 1;
    while (two - 1 < n) {
      ++p;
      two *= 2;
    }

    parent_.resize(p);
    for (auto& p : parent_) {
      p.resize(n);
    }
    depth_.resize(n);

    Dfs(root, -1, 0);

    for (int i = 1; i < p; ++i) {
      for (int j = 0; j < n; ++j) {
        parent_[i][j] = parent_[i - 1][parent_[i - 1][j]];
      }
    }
  }

  int Of(int u, int v) const {
    if (depth_[u] > depth_[v]) {
      std::swap(u, v);
    }
    for (int i = parent_.size() - 1; i >= 0; --i) {
      if (depth_[v] - (1 << i) >= depth_[u]) {
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
    return parent_[0][u];
  }

  int Depth(int i) const { return depth_[i]; }
  int Parent(int i) const { return parent_[0][i]; }

 private:
  void Dfs(int node, int parent, int depth) {
    depth_[node] = depth;
    for (auto& e : graph_.Edges(node)) {
      int child = e.to;
      if (child == parent) continue;
      parent_[0][child] = node;
      Dfs(child, node, depth + 1);
    }
  }

  const Graph<int>& graph_;
  std::vector<std::vector<int>> parent_;
  std::vector<int> depth_;
};
