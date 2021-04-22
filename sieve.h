#include <map>
#include <numeric>
#include <vector>

class Sieve {
 public:
  Sieve(int64_t n) : v_(n + 1) {
    std::iota(v_.begin(), v_.end(), 0);
    for (int32_t i = 2; i * i <= n; ++i) {
      if (v_[i] == i) {
        for (int32_t j = i * i; j <= n; j += i) {
          v_[j] = i;
        }
      }
    }
  }
  std::map<int64_t, int64_t> Factors(int64_t n) {
    std::map<int64_t, int64_t> m;
    while (n > 1) {
      ++m[v_[n]];
      n /= v_[n];
    }
    return m;
  }

 private:
  std::vector<int32_t> v_;
};
