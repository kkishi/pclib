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
    int l = Leaf(begin), r = Leaf(end);
    while (l < r) {
      if (IsRight(l)) {
        v_[l] = operation_(v_[l], v);
        ++l;
      }
      l = Parent(l);
      if (IsRight(r)) {
        v_[r - 1] = operation_(v_[r - 1], v);
      }
      r = Parent(r);
    }
  }
  T Get(int i) const {
    T v = identity_;
    int index = Leaf(i);
    while (true) {
      v = operation_(v, v_[index]);
      if (index == 0) break;
      index = Parent(index);
    }
    return v;
  }

 private:
  int Leaf(int i) const { return i + (v_.size() >> 1); }
  bool IsRight(int i) const { return !(i & 1); }
  int Parent(int i) const { return (i - 1) >> 1; }
  const Operation operation_;
  const T identity_;
  std::vector<T> v_;
};
