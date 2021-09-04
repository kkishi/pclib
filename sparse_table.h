#include <functional>
#include <vector>

template <typename T>
class SparseTable {
 public:
  using Operation = std::function<T(T, T)>;
  SparseTable(const std::vector<T>& v, Operation op) : op_(op) {
    int n = v.size(), p = log2(n);
    v_.resize(p + 1);
    v_[0] = v;
    for (int i = 1; i <= p; ++i) {
      v_[i].resize(n);
      for (int j = 0; j < n; ++j) {
        v_[i][j] = v_[i - 1][j];
        int k = j + (1 << (i - 1));
        if (k < n) v_[i][j] = op_(v_[i][j], v_[i - 1][k]);
      }
    }
  }
  T Get(int l, int r) const {
    int p = log2(r - l);
    return op_(v_[p][l], v_[p][r - (1 << p)]);
  }

 private:
  static int log2(int32_t x) { return 31 - __builtin_clz(x); }
  std::vector<std::vector<T>> v_;
  Operation op_;
};
