#ifndef BIDIRECTED_GRAPH_
#define BIDIRECTED_GRAPH_

#include <memory>
#include <vector>

template <typename T>
class BidirectedGraph {
 public:
  struct Edge {
    int from, to;
    T weight;
    Edge* back = nullptr;
    Edge(int from, int to, T weight = T())
        : from(from), to(to), weight(weight) {}
  };

  BidirectedGraph(int n) : edges_(n) {}
  std::pair<Edge&, Edge&> AddEdge(int from, int to, T weight = T()) {
    Edge& forward = AddDirectedEdge(from, to, weight);
    Edge& back = AddDirectedEdge(to, from, weight);
    forward.back = &back;
    back.back = &forward;
    return {forward, back};
  }
  const std::vector<std::unique_ptr<Edge>>& Edges(int from) const {
    return edges_[from];
  }
  int NumVertices() const { return edges_.size(); }

 private:
  Edge& AddDirectedEdge(int from, int to, T weight = T()) {
    edges_[from].push_back(std::make_unique<Edge>(from, to, weight));
    return *edges_[from].back();
  }

  std::vector<std::vector<std::unique_ptr<Edge>>> edges_;
};

#endif  // BIDIRECTED_GRAPH_
