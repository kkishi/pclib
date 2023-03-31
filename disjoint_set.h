#ifndef DISJOINT_SET_H_
#define DISJOINT_SET_H_

#include <algorithm>
#include <utility>
#include <vector>

class DisjointSet {
 public:
  DisjointSet(int size) : parent_(size), size_(size, 1) {
    for (int i = 0; i < size; ++i) {
      parent_[i] = i;
    }
  }
  // Returns the root of the group to which x belongs.
  int Find(int x) {
    int& p = parent_[x];
    if (p != x) p = Find(p);
    return p;
  }
  // Unions p and c such that Find(p) becomes the parent of Find(c).
  // Returns the new root (= Find(p)).
  int Union(int p, int c) {
    p = Find(p), c = Find(c);
    if (p != c) {
      parent_[c] = p;
      size_[p] += size_[c];
    }
    return p;
  }
  int Size(int x) { return size_[Find(x)]; }
  bool Same(int x, int y) { return Find(x) == Find(y); }

  // Returns the elements of the group to which x belongs.
  std::vector<int> Group(int x) {
    int n = size_.size();
    std::vector<int> g;
    for (int i = 0; i < n; ++i) {
      if (Find(i) == Find(x)) g.push_back(i);
    }
    return g;
  }
  // Returns the elements of each group.
  std::vector<std::vector<int>> Groups() {
    int n = size_.size();
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
      g[Find(i)].push_back(i);
    }
    g.erase(std::remove(g.begin(), g.end(), std::vector<int>()), g.end());
    return g;
  }

 private:
  std::vector<int> parent_, size_;
};

#endif  // DISJOINT_SET_H_
