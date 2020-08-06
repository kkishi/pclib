#include <functional>
#include <vector>

template <typename T>
class DualSegmentTree {
 public:
  using Operation = std::function<T(T, T)>;
  DualSegmentTree(int size, Operation operation, T identity = T())
      : operation_(operation), identity_(identity) {
    int two = 1;
    while (two < size) {
      two <<= 1;
    }
    v_.resize(two * 2 - 1, identity_);
  }
  void Update(int begin, int end, T v) {
    std::function<void(int, int, int)> rec = [&](int cbegin, int cend,
                                                 int index) {
      if (begin <= cbegin && cend <= end) {
        v_[index] = operation_(v_[index], v);
        return;
      }
      if (cend <= begin || end <= cbegin) {
        return;
      }
      int cmid = (cbegin + cend) / 2;
      rec(cbegin, cmid, index * 2 + 1);
      rec(cmid, cend, index * 2 + 2);
    };
    rec(0, (v_.size() + 1) / 2, 0);
  }
  T Get(int i) const {
    T v = identity_;
    int index = v_.size() / 2 + i;
    while (true) {
      v = operation_(v, v_[index]);
      if (index == 0) break;
      index = (index - 1) / 2;
    }
    return v;
  }

 private:
  const Operation operation_;
  const T identity_;
  std::vector<T> v_;
};
