#include <functional>
#include <vector>

template <typename T>
class RangeSegmentTree {
 public:
  using Operation = std::function<T(T, T)>;
  using RangeOperation = std::function<T(T, int)>;

  RangeSegmentTree(
      int size, Operation operation, T identity = T(),
      RangeOperation range_operation = [](T v, int) { return v; })
      : operation_(operation),
        identity_(identity),
        range_operation_(range_operation) {
    int two = 1;
    while (two < size) {
      two <<= 1;
    }
    v_.resize(two * 2 - 1, identity_);
    l_.resize(two * 2 - 1, identity_);
  }

  void Apply(int begin, int end, T v) {
    std::function<void(int, int, int)> rec = [&](int cbegin, int cend,
                                                 int index) {
      if (begin <= cbegin && cend <= end) {
        l_[index] = operation_(l_[index], v);
        return;
      }
      if (cend <= begin || end <= cbegin) {
        return;
      }
      int cmid = (cbegin + cend) / 2;
      rec(cbegin, cmid, index * 2 + 1);
      rec(cmid, cend, index * 2 + 2);
      int size = std::min(cend, end) - std::max(cbegin, begin);
      v_[index] = operation_(v_[index], range_operation_(v, size));
    };
    rec(0, (v_.size() + 1) / 2, 0);
  }

  T Get(int i) const { return Aggregate(i, i + 1); }
  T Aggregate(int begin, int end) const {
    std::function<T(int, int, int)> rec = [&](int cbegin, int cend, int index) {
      int size = std::min(cend, end) - std::max(cbegin, begin);
      if (begin <= cbegin && cend <= end) {
        return operation_(v_[index], range_operation_(l_[index], size));
      }
      if (cend <= begin || end <= cbegin) {
        return identity_;
      }
      int cmid = (cbegin + cend) / 2;
      return operation_(operation_(rec(cbegin, cmid, index * 2 + 1),
                                   rec(cmid, cend, index * 2 + 2)),
                        range_operation_(l_[index], size));
    };
    return rec(0, (v_.size() + 1) / 2, 0);
  }

 private:
  const Operation operation_;
  const T identity_;
  const RangeOperation range_operation_;
  std::vector<T> v_;
  std::vector<T> l_;
};

template <typename T>
RangeSegmentTree<T> AdditiveSegmentTree(int size) {
  auto add = [](T a, T b) { return a + b; };
  auto mul = [](T v, int size) { return v * size; };
  return RangeSegmentTree<T>(size, add, T(), mul);
}

template <typename T>
RangeSegmentTree<T> MinimumSegmentTree(int size) {
  auto minimum = [](T a, T b) { return std::min(a, b); };
  auto id = [](T v, int) { return v; };
  return RangeSegmentTree<T>(size, minimum, std::numeric_limits<T>::max(), id);
}
