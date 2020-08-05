#include <functional>
#include <vector>

template <typename T>
class SegmentTree {
 public:
  using Operation = std::function<T(T, T)>;
  SegmentTree(int size, Operation operation, T identity = T())
      : operation_(operation), identity_(identity) {
    int two = 1;
    while (two < size) {
      two <<= 1;
    }
    v_.resize(two * 2 - 1, identity_);
  }
  void Set(int i, T v) {
    int index = v_.size() / 2 + i;
    while (true) {
      v_[index] = v;
      if (index == 0) break;
      v = operation_(v, v_[index + (index % 2 == 0 ? -1 : 1)]);
      index = (index - 1) / 2;
    }
  }
  T Get(int i) const { return Aggregate(i, i + 1); }
  T Aggregate(int begin, int end) const {
    std::function<T(int, int, int)> rec = [&](int cbegin, int cend, int index) {
      if (begin <= cbegin && cend <= end) {
        return v_[index];
      }
      if (cend <= begin || end <= cbegin) {
        return identity_;
      }
      int cmid = (cbegin + cend) / 2;
      return operation_(rec(cbegin, cmid, index * 2 + 1),
                        rec(cmid, cend, index * 2 + 2));
    };
    return rec(0, (v_.size() + 1) / 2, 0);
  }

 private:
  const Operation operation_;
  const T identity_;
  std::vector<T> v_;
};
