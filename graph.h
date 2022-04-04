#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>

#include "dassert.h"
#include "fix.h"

class Graph : public std::vector<std::vector<int64_t>> {
 public:
  using std::vector<std::vector<int64_t>>::vector;  // Inherit constructors.
  void Read() {
    dassert(!empty());
    Read(size() - 1);
    dassert(IsTree());
  }
  void Read(int64_t m) {
    for (int i = 0; i < m; ++i) {
      int a, b;
      std::cin >> a >> b;
      --a, --b;
      dassert(0 <= a && a < size());
      dassert(0 <= b && b < size());
      (*this)[a].push_back(b);
      (*this)[b].push_back(a);
    }
  }
  bool IsTree() const {
    std::vector<bool> visited(size());
    return Fix([&](auto rec, int node, int parent) -> bool {
      if (visited[node]) return false;
      visited[node] = true;
      for (auto child : (*this)[node]) {
        if (child != parent && !rec(child, node)) return false;
      }
      return true;
    })(0, -1);
  }
};

template <typename T>
class WeightedGraph : public std::vector<std::vector<std::pair<int64_t, T>>> {
 public:
  using std::vector<
      std::vector<std::pair<int64_t, T>>>::vector;  // Inherit constructors.
  void Read() {
    dassert(!this->empty());
    Read(this->size() - 1);
    dassert(IsTree());
  }
  void Read(int64_t m) {
    for (int i = 0; i < m; ++i) {
      int a, b;
      T c;
      std::cin >> a >> b >> c;
      --a, --b;
      dassert(0 <= a && a < this->size());
      dassert(0 <= b && b < this->size());
      (*this)[a].emplace_back(b, c);
      (*this)[b].emplace_back(a, c);
    }
  }
  bool IsTree() const {
    std::vector<bool> visited(this->size());
    return Fix([&](auto rec, int node, int parent) -> bool {
      if (visited[node]) return false;
      visited[node] = true;
      for (auto [child, _] : (*this)[node]) {
        if (child != parent && !rec(child, node)) return false;
      }
      return true;
    })(0, -1);
  }
};

#endif  // GRAPH_H_
