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
  void Union(int x, int y) {
    x = Find(x), y = Find(y);
    if (x == y) return;
    if (Size(x) > Size(y)) std::swap(x, y);
    parent_[x] = parent_[y];
    size_[x] += size_[y];
  }
  int Size(int x) const { return size_[Find(x)]; }

 private:
  std::vector<int> parent_, size_;
};
