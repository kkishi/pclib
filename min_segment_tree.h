#include "segment_tree.h"

template <typename T>
class MinSegmentTree : public SegmentTree<T> {
 public:
  MinSegmentTree(int n)
      : SegmentTree<T>(
            n, [](T a, T b) { return std::min(a, b); },
            std::numeric_limits<T>::max()) {}
};
