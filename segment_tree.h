#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

template <typename T>
class SegmentTree {
 public:
  using Operation = std::function<T(T, T)>;
  using RangeOperation = std::function<T(T, int)>;

  SegmentTree(
      int size, Operation operation, T identity = T(),
      RangeOperation range_operation = [](int v, int) { return v; })
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

  void Set(int i, T v) {
    int index = v_.size() / 2 + i;
    while (true) {
      v_[index] = v;
      if (index == 0) break;
      v = operation_(v, v_[index + (index % 2 == 0 ? -1 : 1)]);
      index = (index - 1) / 2;
    }
  }
  void Apply(int begin, int end, T v) {
    std::function<void(int, int, int)> rec = [&](int cbegin, int cend,
                                                 int index) {
      int size = std::min(cend, end) - std::max(cbegin, begin);
      eval(index, size);
      if (begin <= cbegin && cend <= end) {
        l_[index] = operation_(l_[index], v);
        eval(index, size);
        return;
      }
      if (cend <= begin || end <= cbegin) {
        return;
      }
      int cmid = (cbegin + cend) / 2;
      rec(cbegin, cmid, index * 2 + 1);
      rec(cmid, cend, index * 2 + 2);
      v_[index] = operation_(v_[index], range_operation_(v, size));
    };
    rec(0, (v_.size() + 1) / 2, 0);
  }

  T Get(int i) { return Aggregate(i, i + 1); }
  T Aggregate(int begin, int end) {
    std::function<T(int, int, int)> rec = [&](int cbegin, int cend, int index) {
      int size = std::min(cend, end) - std::max(cbegin, begin);
      eval(index, size);
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

  void Debug() const {
    auto debug = [&](const std::vector<T>& v) {
      int width = 0;
      for (T t : v) {
        std::stringstream ss;
        ss << t;
        width = std::max<int>(width, ss.str().size());
      }
      const int N = (v.size() + 1) / 2;
      int index = 0;  // Index in this level.
      int twos = 1;   // Number of elements in this level.
      std::string separator = '|' + std::string(N * (width + 1) - 1, '-') + '|';
      std::cerr << separator << std::endl;
      for (T t : v) {
        if (index == 0) {
          std::cerr << '|';
        }
        std::cerr << std::string((width + 1) * (N / twos - 1), ' ');
        std::cerr << std::setw(width) << t << '|';
        ++index;
        if (index == twos) {
          index = 0;
          twos <<= 1;
          std::cerr << std::endl << separator << std::endl;
        }
      }
    };
    std::cerr << "v_:" << std::endl;
    debug(v_);
    std::cerr << "l_:" << std::endl;
    debug(l_);
  }

 private:
  void eval(int index, int size) {
    if (index <= v_.size() / 2) {
      l_[index * 2 + 1] = operation_(l_[index * 2 + 1], l_[index]);
      l_[index * 2 + 2] = operation_(l_[index * 2 + 2], l_[index]);
    }
    v_[index] = operation_(v_[index], range_operation_(l_[index], size));
    l_[index] = identity_;
  }

  const Operation operation_;
  const T identity_;
  const RangeOperation range_operation_;
  std::vector<T> v_;
  std::vector<T> l_;
};

template <typename T>
SegmentTree<T> AdditiveSegmentTree(int size) {
  auto add = [](T a, T b) { return a + b; };
  auto mul = [](T v, int size) { return v * size; };
  return SegmentTree<T>(size, add, T(), mul);
}

template <typename T>
SegmentTree<T> MinimumSegmentTree(int size) {
  auto minimum = [](T a, T b) { return std::min(a, b); };
  auto id = [](T v, int) { return v; };
  return SegmentTree<T>(size, minimum, std::numeric_limits<T>::max(), id);
}
