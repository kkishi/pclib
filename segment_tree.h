#include <vector>

class SegmentTree {
 public:
  SegmentTree(int size) {
    int two = 1;
    while (two < size) {
      two <<= 1;
    }
    v_.resize(two * 2 - 1);
  }
  void Add(int i, int v) {
    int index = v_.size() / 2 + i;
    while (true) {
      v_[index] += v;
      if (index == 0) break;
      index = (index - 1) / 2;
    }
  }
  int Sum(int begin, int end) const {
    return sum(begin, end, 0, (v_.size() + 1) / 2, 0);
  }
  int sum(int begin, int end, int cbegin, int cend, int index) const {
    if (begin <= cbegin && cend <= end) {
      return v_[index];
    }
    if (cend <= begin || end <= cbegin) {
      return 0;
    }
    int cmid = (cbegin + cend) / 2;
    return sum(begin, end, cbegin, cmid, index * 2 + 1) +
           sum(begin, end, cmid, cend, index * 2 + 2);
  }
  std::vector<int> v_;
};
