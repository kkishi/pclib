#include <functional>
#include <vector>

template <typename T>
class DualSegmentTree {
 public:
  using Operation = std::function<T(T, T)>;
  DualSegmentTree(int size, Operation operation, T identity = T())
      : operation_(operation), identity_(identity) {
    log2_ = 0;
    int pow2 = 1;
    while (pow2 < size) {
      ++log2_;
      pow2 <<= 1;
    }
    v_.resize(1 << (log2_ + 1), identity_);
  }
  void Update(int begin, int end, T v) {
    Eval(begin);
    Eval(end - 1);
    int l = Leaf(begin), r = Leaf(end);
    while (l < r) {
      if (IsRight(l)) {
        v_[l] = operation_(v, v_[l]);
        ++l;
      }
      l = Parent(l);
      if (IsRight(r)) {
        v_[r - 1] = operation_(v, v_[r - 1]);
      }
      r = Parent(r);
    }
  }
  T Get(int i) {
    Eval(i);
    return v_[Leaf(i)];
  }

 private:
  void Eval(int i) {
    for (int j = log2_; j >= 1; --j) {
      int p = Parent(Leaf(i), j);
      v_[Left(p)] = operation_(v_[p], v_[Left(p)]);
      v_[Right(p)] = operation_(v_[p], v_[Right(p)]);
      v_[p] = identity_;
    }
  }
  int log2_;
  int Leaf(int i) const { return i + (1 << log2_); }
  bool IsRight(int i) const { return i & 1; }
  int Parent(int i, int j = 1) const { return i >> j; }
  int Left(int i) const { return i << 1; }
  int Right(int i) const { return Left(i) + 1; }
  const Operation operation_;
  const T identity_;
  std::vector<T> v_;
};
