#include "segment_tree.h"

template <typename T>
class AddSegmentTree : public SegmentTree<T> {
 public:
  AddSegmentTree(int n) : SegmentTree<T>(n, [](T a, T b) { return a + b; }) {}
  void Add(int i, T v) { this->Set(i, this->Get(i) + v); }
};
