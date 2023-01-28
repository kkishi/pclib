#include <cstdint>
#include <random>
#include <vector>

#include "dassert.h"
#include "pow.h"

class RollingHashCumulativeSum {
  using u64 = uint64_t;

 public:
  RollingHashCumulativeSum(const std::string& s) {
    int n = s.size();
    hash_.resize(n + 1);
    for (int i = 0; i < n; ++i) {
      hash_[i + 1] = Add(Mul(hash_[i], base()), s[i]);
    }
  }
  u64 Hash(int l, int r) {
    return Sub(hash_[r], Mul(hash_[l], BasePow(r - l)));
  }
  u64 Hash(int r) const { return hash_[r]; }

  static u64 base() {
    if (base_ == 0) {
      std::random_device d;
      std::mt19937 g(d());
      const u64 r = 37;
      while (true) {
        u64 k = std::uniform_int_distribution<u64>(1, mod_ - 2)(g);
        if (std::gcd(k, mod_ - 1) == 1) {
          base_ = Pow(r, k, mod_);
          break;
        }
      }
    }
    return base_;
  }

 private:
  u64 BasePow(int n) {
    dassert(n <= 10000000);
    for (int i = base_pow_.size(); i <= n; ++i) {
      base_pow_.push_back(i == 0 ? 1 : Mul(base_pow_.back(), base()));
    }
    return base_pow_[n];
  }
  static u64 Mul(u64 x, u64 y) { return (__uint128_t(x) * y) % mod_; }
  static u64 Add(u64 x, u64 y) { return (__uint128_t(x) + y) % mod_; }
  static u64 Sub(u64 x, u64 y) { return Add(x, mod_ - y); }

  static const u64 mod_ = (1ULL << 61) - 1;
  inline static u64 base_ = 0;
  inline static std::vector<u64> base_pow_;
  std::vector<u64> hash_;
};
