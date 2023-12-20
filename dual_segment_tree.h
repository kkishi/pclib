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
    std::vector<int> v;
    int index = Leaf(i);
    while (index != 0) {
      index = Parent(index);
      v.push_back(index);
    }
    for (size_t i = 0; i < v.size(); ++i) {
      int index = v[v.size() - 1 - i];
      v_[Left(index)] = operation_(v_[index], v_[Left(index)]);
      v_[Right(index)] = operation_(v_[index], v_[Right(index)]);
      v_[index] = identity_;
    }
  }
  int Leaf(int i) const { return i + (v_.size() >> 1); }
  bool IsRight(int i) const { return !(i & 1); }
  int Parent(int i) const { return (i - 1) >> 1; }
  int Left(int i) const { return (i << 1) + 1; }
  int Right(int i) const { return (i << 1) + 2; }
  const Operation operation_;
  const T identity_;
  std::vector<T> v_;
};
