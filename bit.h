#include <vector>

template <typename T>
class BIT {
 public:
  BIT(int n) : v_(n + 1) {}
  T Sum(int i) const {
    T ret = 0;
    while (i) {
      ret += v_[i];
      i -= i & -i;
    }
    return ret;
  }
  T Get(int i) const { return Sum(i) - Sum(i - 1); }
  void Add(int i, T v) {
    while (i < v_.size()) {
      v_[i] += v;
      i += i & -i;
    }
  }

 private:
  std::vector<T> v_;
};
