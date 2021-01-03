#pragma once
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
  int NumVertices() const { return edges_.size(); }

 private:
  std::vector<std::vector<Edge>> edges_;
};
