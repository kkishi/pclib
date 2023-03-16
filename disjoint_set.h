#ifndef DISJOINT_SET_H_
#define DISJOINT_SET_H_

#include <utility>
#include <vector>

class DisjointSet {
 public:
  DisjointSet(int size) : parent_(size), size_(size, 1) {
    for (int i = 0; i < size; ++i) {
      parent_[i] = i;
    }
  }
  int Find(int x) {
    int& p = parent_[x];
    if (p != x) p = Find(p);
    return p;
  }
  bool Union(int x, int y) {
    x = Find(x), y = Find(y);
    if (x == y) return false;
    if (Size(x) > Size(y)) std::swap(x, y);
    parent_[x] = parent_[y];
    size_[y] += size_[x];
    return true;
  }
  int Size(int x) { return size_[Find(x)]; }
  bool Same(int x, int y) { return Find(x) == Find(y); }

 private:
  std::vector<int> parent_, size_;
};

#endif  // DISJOINT_SET_H_
