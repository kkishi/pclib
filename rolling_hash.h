#include <cstdint>
#include <functional>
#include <random>

#include "pow.h"

class RollingHash {
 public:
  void Add(uint64_t i) {
    __uint128_t h = hash_;
    h *= base();
    h %= mod();
    h += i;
    h %= mod();
    hash_ = h;
  }
  uint64_t hash() const { return hash_; }
  bool operator==(const RollingHash& h) const { return hash_ == h.hash_; }

  static uint64_t mod() { return mod_; }
  static uint64_t base() {
    if (base_ == 0) {
      std::random_device d;
      std::mt19937 g(d());
      const uint64_t r = 37;
      while (true) {
        uint64_t k = std::uniform_int_distribution<uint64_t>(1, mod() - 2)(g);
        if (std::gcd(k, mod() - 1) == 1) {
          base_ = Pow(r, k, mod());
          break;
        }
      }
    }
    return base_;
  }

 private:
  static const uint64_t mod_ = (1ULL << 61) - 1;
  inline static uint64_t base_ = 0;
  uint64_t hash_ = 0;
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
