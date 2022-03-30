#include "segment_tree.h"

template <typename T>
class MaxSegmentTree : public SegmentTree<T> {
 public:
  MaxSegmentTree(int n)
      : SegmentTree<T>(
            n, [](T a, T b) { return std::max(a, b); },
            std::numeric_limits<T>::min()) {}
};
