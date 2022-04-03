#include <cstdint>
#include <vector>

#include "dassert.h"
#include "graph.h"

enum AttributeLocation { attr_on_node, attr_on_edge };

template <typename T>
class HeavyLightDecomposition {
 public:
  // Compute Heavy Light Decomposition on a rooted tree.
  HeavyLightDecomposition(const Graph<T>& g, AttributeLocation loc,
                          int root = 0)
      : g_(g), loc_(loc) {
    dassert(g.IsTree());
    attr_.resize(g.NumVertices());
    Dfs1(root, -1, 0);
    int index = 0;
    Dfs2(root, -1, root, index);
  }
  // Returns intervals that corresponds to the path from u to v.
  std::vector<std::pair<int32_t, int32_t>> Path(int u, int v) const {
    std::vector<std::pair<int32_t, int32_t>> ret;
    while (Head(u) != Head(v)) {
      if (Depth(Head(u)) < Depth(Head(v))) std::swap(u, v);
      ret.emplace_back(In(Head(u)), In(u) + 1);
      u = Parent(Head(u));
    }
    u = In(u), v = In(v);
    if (u > v) std::swap(u, v);
    ret.emplace_back(u + (loc_ == attr_on_node ? 0 : 1), v + 1);
    return ret;
  }
  // Returns the interval that corresponds to the subtree of v.
  std::pair<int32_t, int32_t> Subtree(int v) const {
    return {In(v) + (loc_ == attr_on_node ? 0 : 1), Out(v)};
  }
  int LCA(int u, int v) const {
    while (Head(u) != Head(v)) {
      if (Depth(Head(u)) < Depth(Head(v))) std::swap(u, v);
      u = Parent(Head(u));
    }
    return Depth(u) < Depth(v) ? u : v;
  }

  int64_t IndexOf(int node) const {
    dassert(loc_ == attr_on_node);
    return In(node);
  }
  int64_t IndexOf(int u, int v) const {
    dassert(loc_ == attr_on_edge);
    return In(Parent(u) == v ? u : v);
  }
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
  void Dfs2(int node, int parent, int head, int& index) {
    Attr& a = attr_[node];
    a.in = index++;
    a.head = head;
    if (a.heavy != -1) {
      Dfs2(a.heavy, node, head, index);
      for (const auto& e : g_.Edges(node)) {
        if (e.to == parent || e.to == a.heavy) continue;
        Dfs2(e.to, node, e.to, index);
      }
    }
    a.out = index;
  }
  int32_t Depth(int node) const { return attr_[node].depth; }
  int32_t Head(int node) const { return attr_[node].head; }
  int32_t Heavy(int node) const { return attr_[node].heavy; }
  int32_t In(int node) const { return attr_[node].in; }
  int32_t Out(int node) const { return attr_[node].out; }
  int32_t Size(int node) const { return attr_[node].size; }

  const Graph<T>& g_;
  const AttributeLocation loc_;
  struct Attr {
    int32_t depth;
    int32_t head;
    int32_t heavy;
    int32_t in;
    int32_t out;
    int32_t parent;
    int32_t size;
  };
  std::vector<Attr> attr_;
};
