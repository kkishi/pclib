#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

template <typename T>
class Graph {
 public:
  struct Edge {
    int from, to;
    T weight;
  };

  Graph(int n) : edges_(n) {}
  void AddEdge(int from, int to, T weight = T()) {
    edges_[from].push_back({from, to, weight});
  }
  const std::vector<Edge> &Edges(int from) const { return edges_[from]; }
  std::vector<Edge> &MutableEdges(int from) { return edges_[from]; }
  int NumVertices() const { return edges_.size(); }
  bool IsTree() const {
    std::vector<bool> visited(NumVertices());
    auto rec = [&](auto rec, int node, int parent) -> bool {
      if (visited[node]) return false;
      visited[node] = true;
      for (const Edge &e : Edges(node)) {
        if (e.to != parent && !rec(rec, e.to, node)) {
          return false;
        }
      }
      return true;
    };
    return rec(rec, 0, -1);
  }

 private:
  std::vector<std::vector<Edge>> edges_;
};

#endif
