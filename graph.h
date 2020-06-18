#pragma once
#include <vector>

template <typename T>
struct Edge {
  int from, to;
  T weight;
};

template <typename T>
class Graph {
 public:
  Graph(int n) : edges_(n) {}
  void AddEdge(int from, int to, T weight) {
    edges_[from].push_back({from, to, weight});
  }
  const std::vector<Edge<T>>& Edges(int from) const { return edges_[from]; }
  int NumVertices() const { return edges_.size(); }

 private:
  std::vector<std::vector<Edge<T>>> edges_;
};
