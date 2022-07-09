#include <cstdint>
#include <functional>
#include <queue>
#include <random>
#include <vector>

#include "dassert.h"
#include "pow.h"

class RollingHash {
  using u64 = uint64_t;

 public:
  void PushBack(u64 x) {
    hash_ = Add(Mul(hash_, base()), x);
    values_.push_back(x);
  }
  void PushFront(u64 x) {
    hash_ = Add(hash_, Mul(BasePow(values_.size()), x));
    values_.push_front(x);
  }
  void PopFront() {
    u64 x = values_.front();
    values_.pop_front();
    hash_ = Sub(hash_, Mul(BasePow(values_.size()), x));
  }
  u64 hash() const { return hash_; }
  bool operator==(const RollingHash& h) const { return hash_ == h.hash_; }

  static u64 mod() { return mod_; }
  static u64 base() {
    if (base_ == 0) {
      std::random_device d;
      std::mt19937 g(d());
      const u64 r = 37;
      while (true) {
        u64 k = std::uniform_int_distribution<u64>(1, mod() - 2)(g);
        if (std::gcd(k, mod() - 1) == 1) {
          base_ = Pow(r, k, mod());
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
  static u64 Mul(u64 x, u64 y) { return (__uint128_t(x) * y) % mod(); }
  static u64 Add(u64 x, u64 y) { return (__uint128_t(x) + y) % mod(); }
  static u64 Sub(u64 x, u64 y) { return Add(x, mod() - y); }

  static const u64 mod_ = (1ULL << 61) - 1;
  inline static u64 base_ = 0;
  inline static std::vector<u64> base_pow_;
  u64 hash_ = 0;
  int size_ = 0;
  std::deque<u64> values_;
};

namespace std {
template <>
class hash<RollingHash> {
 public:
  size_t operator()(const RollingHash& h) const {
    return hash<uint64_t>()(h.hash());
  }
};
}  // namespace std
