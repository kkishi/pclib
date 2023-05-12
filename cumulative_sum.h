#include <vector>

#include "dassert.h"

template <typename T>
class CumulativeSum1D {
 public:
  CumulativeSum1D(const std::vector<T> &val) : sum_(val), n_(val.size()) {
    for (int i = 1; i < n_; ++i) {
      sum_[i] += sum_[i - 1];
    }
  }
  // Returns sum(val(r)) for i<=r<=j.
  T Get(int i, int j) const {
    if (i > j) return 0;
    return Get(j) - Get(i - 1);
  }
  // Returns sum(val(r)) for r<=i.
  T Get(int i) const {
    if (i < 0) return T();
    return sum_[std::min(i, n_ - 1)];
  }

 private:
  std::vector<T> sum_;
  int n_;
};

template <typename T>
class CumulativeSum2D {
 public:
  CumulativeSum2D(const std::vector<std::vector<T>> &val)
      : sum_(val), n_(val.size()), m_(val[0].size()) {
    for (int i = 0; i < n_; ++i) {
      for (int j = 1; j < m_; ++j) {
        sum_[i][j] += sum_[i][j - 1];
      }
    }
    for (int i = 1; i < n_; ++i) {
      for (int j = 0; j < m_; ++j) {
        sum_[i][j] += sum_[i - 1][j];
      }
    }
  }
  // Returns sum(val(r, c)) for i<=r<=k, j<=c<=l.
  T Get(int i, int j, int k, int l) const {
    if (i > k || j > l) return 0;
    return Get(k, l) - Get(i - 1, l) - Get(k, j - 1) + Get(i - 1, j - 1);
  }
  // Returns sum(val(r, c)) for r<=i, c<=j.
  T Get(int i, int j) const {
    if (i < 0 || j < 0) return T();
    return sum_[std::min(i, n_ - 1)][std::min(j, m_ - 1)];
  }

 private:
  std::vector<std::vector<T>> sum_;
  int n_, m_;
};
