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
    int index = Leaf(i);
    while (true) {
      v_[index] = v;
      if (index == 0) break;
      if (IsRight(index)) {
        v = operation_(v_[index - 1], v);
      } else {
        v = operation_(v, v_[index + 1]);
      }
      index = Parent(index);
    }
  }
  T Get(int i) const { return Aggregate(i, i + 1); }
  T Aggregate(int begin, int end) const {
    int l = Leaf(begin), r = Leaf(end);
    T v = identity_;
    while (l < r) {
      if (IsRight(l)) {
        v = operation_(v, v_[l]);
        ++l;
      }
      l = Parent(l);
      if (IsRight(r)) {
        v = operation_(v_[r - 1], v);
      }
      r = Parent(r);
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
