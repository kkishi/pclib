#include <vector>

template <typename T>
class BIT {
 public:
  BIT(int n) : v_(n) {}
  T Sum(int i) const {
    T ret = 0;
    while (i >= 0) {
      ret += v_[i];
      i = (i & (i + 1)) - 1;
    }
    return ret;
  }
  T Get(int i) const { return Sum(i) - Sum(i - 1); }
  void Add(int i, T v) {
    while (i < v_.size()) {
      v_[i] += v;
      i |= i + 1;
    }
  }

 private:
  std::vector<T> v_;
};
