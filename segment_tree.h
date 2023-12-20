#include <functional>
#include <vector>

template <typename T>
class SegmentTree {
 public:
  using Operation = std::function<T(T, T)>;
  SegmentTree(int size, Operation operation, T identity = T())
      : operation_(operation), identity_(identity) {
    log2_ = 0;
    int pow2 = 1;
    while (pow2 < size) {
      ++log2_;
      pow2 <<= 1;
    }
    v_.resize(1 << (log2_ + 1), identity_);
  }
  void Set(int i, T v) {
    int idx = Leaf(i);
    while (true) {
      v_[idx] = v;
      if (idx == 1) break;
      if (IsRight(idx)) {
        v = operation_(v_[idx - 1], v);
      } else {
        v = operation_(v, v_[idx + 1]);
      }
      idx = Parent(idx);
    }
  }
  T Get(int i) const { return Aggregate(i, i + 1); }
  T Aggregate(int begin, int end) const {
    int l = Leaf(begin), r = Leaf(end);
    T lv = identity_, rv = identity_;
    while (l < r) {
      if (IsRight(l)) {
        lv = operation_(lv, v_[l]);
        ++l;
      }
      l = Parent(l);
      if (IsRight(r)) {
        rv = operation_(v_[r - 1], rv);
      }
      r = Parent(r);
    }
    return operation_(lv, rv);
  }

 private:
  int log2_;
  int Leaf(int i) const { return i + (1 << log2_); }
  bool IsRight(int i) const { return i & 1; }
  int Parent(int i) const { return i >> 1; }
  const Operation operation_;
  const T identity_;
  std::vector<T> v_;
};
