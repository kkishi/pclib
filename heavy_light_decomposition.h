#include <cstdint>
#include <vector>

#include "graph.h"

template <typename T>
class HeavyLightDecomposition {
 public:
  HeavyLightDecomposition(const Graph<T>& g, int root = 0) : g_(g) {
#ifdef DEBUG
    assert(g.IsTree());
#endif
    int n = g.NumVertices();
    attr_.resize(n);
    Dfs1(root, -1, 0);
    int index = 0;
    Dfs2(root, -1, root, index);
  }
  std::vector<std::pair<int32_t, int32_t>> Query(
      int u, int v, bool include_lca = false) const {
    std::vector<std::pair<int32_t, int32_t>> ret;
    while (Begin(u) != Begin(v)) {
      if (Depth(Begin(u)) < Depth(Begin(v))) std::swap(u, v);
      ret.emplace_back(Index(Begin(u)), Index(u) + 1);
      u = Parent(Begin(u));
    }
    u = Index(u), v = Index(v);
    if (u > v) std::swap(u, v);
    ret.emplace_back(u + (include_lca ? 0 : 1), v + 1);
    return ret;
  }
  int LCA(int u, int v) const {
    while (Begin(u) != Begin(v)) {
      if (Depth(Begin(u)) < Depth(Begin(v))) std::swap(u, v);
      u = Parent(Begin(u));
    }
    return Depth(u) < Depth(v) ? u : v;
  }
  int32_t Index(int node) const { return attr_[node].index; }
  int32_t Parent(int node) const { return attr_[node].parent; }

 private:
  void Dfs1(int node, int parent, int depth) {
    Attr& a = attr_[node];
    a.depth = depth;
    a.parent = parent;
    a.size = 1;
    a.heavy = -1;
    for (const auto& e : g_.Edges(node)) {
      if (e.to == parent) continue;
      Dfs1(e.to, node, depth + 1);
      a.size += Size(e.to);
      if (a.heavy == -1 || Size(a.heavy) < Size(e.to)) {
        a.heavy = e.to;
      }
    }
  }
  void Dfs2(int node, int parent, int begin, int& index) {
    Attr& a = attr_[node];
    a.index = index++;
    a.begin = begin;
    if (a.heavy == -1) return;
    Dfs2(a.heavy, node, begin, index);
    for (const auto& e : g_.Edges(node)) {
      if (e.to == parent || e.to == a.heavy) continue;
      Dfs2(e.to, node, e.to, index);
    }
  }
  int32_t Begin(int node) const { return attr_[node].begin; }
  int32_t Depth(int node) const { return attr_[node].depth; }
  int32_t Heavy(int node) const { return attr_[node].heavy; }
  int32_t Size(int node) const { return attr_[node].size; }

  const Graph<T>& g_;
  struct Attr {
    int32_t begin;
    int32_t depth;
    int32_t heavy;
    int32_t index;
    int32_t parent;
    int32_t size;
  };
  std::vector<Attr> attr_;
};
