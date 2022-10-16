#include <vector>

#include "dassert.h"
#include "fix.h"
#include "graph.h"

class RootedTree {
 public:
  RootedTree(const Graph& graph, int root = 0) : graph_(graph) {
    dassert(graph.IsTree());
    const int n = graph.size();
    int p = 1;
    while ((1 << p) < n) ++p;
    parent_.resize(p);
    for (auto& p : parent_) {
      p.resize(n);
    }
    depth_.resize(n);

    Fix([&](auto rec, int node, int parent, int depth) -> void {
      parent_[0][node] = parent;
      depth_[node] = depth;
      for (int child : graph_[node]) {
        if (child == parent) continue;
        rec(child, node, depth + 1);
      }
    })(root, -1, 0);

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
  int Parent(int i, int d) const {  // Returns d-th parent of i.
    dassert(Depth(i) >= d);
    for (int j = 0; j < int(parent_.size()); ++j) {
      if ((d >> j) & 1) {
        i = parent_[j][i];
      }
    }
    return i;
  }

 private:
  const Graph& graph_;
  std::vector<std::vector<int>> parent_;
  std::vector<int> depth_;
};
