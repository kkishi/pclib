#ifndef MODINT_H_
#define MODINT_H_

#include <ostream>
#include <vector>

#include "dassert.h"

namespace {
using i32 = int32_t;
using i64 = int64_t;
}  // namespace

#define BIN_OPS(F) F(+) F(-) F(*) F(/)
#define CMP_OPS(F) F(!=) F(<) F(<=) F(==) F(>) F(>=)

template <i32 Mod = 1000000007>
class ModInt {
 public:
  ModInt() : n_(0) {}
  ModInt(i64 n) : n_(n % Mod) {
    if (n_ < 0) {
      // In C++, (-n)%m == -(n%m).
      n_ += Mod;
    }
  }
  ModInt& operator+=(const ModInt& m) {
    n_ += m.n_;
    if (n_ >= Mod) {
      n_ -= Mod;
    }
    return *this;
  }
  ModInt& operator++() { return (*this) += 1; }
  ModInt& operator-=(const ModInt& m) {
    n_ -= m.n_;
    if (n_ < 0) {
      n_ += Mod;
    }
    return *this;
  }
  ModInt& operator--() { return (*this) -= 1; }
  ModInt& operator*=(const ModInt& m) {
    n_ = i64(n_) * m.n_ % Mod;
    return *this;
  }
  ModInt& operator/=(const ModInt& m) {
    *this *= m.Inv();
    return *this;
  }
#define DEFINE(op) \
  ModInt operator op(const ModInt& m) const { return ModInt(*this) op## = m; }
  BIN_OPS(DEFINE)
#undef DEFINE
#define DEFINE(op) \
  bool operator op(const ModInt& m) const { return n_ op m.n_; }
  CMP_OPS(DEFINE)
#undef DEFINE
  ModInt operator-() const { return ModInt(-n_); }
  ModInt Pow(i64 n) const {
    if (n < 0) {
      return Inv().Pow(-n);
    }
    // a * b ^ n = answer.
    ModInt a = 1, b = *this;
    while (n != 0) {
      if (n & 1) {
        a *= b;
      }
      n /= 2;
      b *= b;
    }
    return a;
  }
  ModInt Inv() const {
    dassert(n_ != 0);
    if (n_ > kMaxCacheSize) {
      // Compute the inverse based on Fermat's little theorem. Note that this
      // only works when n_ and Mod are relatively prime. The theorem says that
      // n_^(Mod-1) = 1 (mod Mod). So we can compute n_^(Mod-2).
      return Pow(Mod - 2);
    }
    for (i64 i = inv_.size(); i <= n_; ++i) {
      inv_.push_back(i <= 1 ? i : (Mod / i * -inv_[Mod % i]));
    }
    return inv_[n_];
  }
  i64 value() const { return n_; }

  static ModInt Fact(i64 n) {
    dassert(0 <= n && n <= kMaxCacheSize);
    for (i64 i = fact_.size(); i <= n; ++i) {
      fact_.push_back(i == 0 ? 1 : fact_.back() * i);
    }
    return fact_[n];
  }
  static ModInt InvFact(i64 n) {
    dassert(0 <= n && n <= kMaxCacheSize);
    for (i64 i = inv_fact_.size(); i <= n; ++i) {
      inv_fact_.push_back(i == 0 ? 1 : inv_fact_.back() / i);
    }
    return inv_fact_[n];
  }
  static ModInt Comb(i64 n, i64 k) {
    if (!Valid(n, k)) return 0;
    return Perm(n, k) * InvFact(k);
  }
  static ModInt CombSlow(i64 n, i64 k) {
    if (!Valid(n, k)) return 0;
    return PermSlow(n, k) * InvFact(k);
  }
  static ModInt Perm(i64 n, i64 k) {
    if (!Valid(n, k)) return 0;
    dassert(n <= kMaxCacheSize &&
            "n is too large. If k is small, consider using PermSlow.");
    return Fact(n) * InvFact(n - k);
  }
  static ModInt PermSlow(i64 n, i64 k) {
    if (!Valid(n, k)) return 0;
    ModInt p = 1;
    for (i64 i = 0; i < k; ++i) {
      p *= (n - i);
    }
    return p;
  }

 private:
  static bool Valid(i64 n, i64 k) { return 0 <= n && 0 <= k && k <= n; }

  i32 n_;
  inline static std::vector<ModInt> fact_;
  inline static std::vector<ModInt> inv_fact_;
  inline static std::vector<ModInt> inv_;
  static const i64 kMaxCacheSize = 10000000;
};

#define DEFINE(op)                                            \
  template <i32 Mod, typename T>                              \
  ModInt<Mod> operator op(const T& t, const ModInt<Mod>& m) { \
    return ModInt<Mod>(t) op m;                               \
  }
BIN_OPS(DEFINE)
CMP_OPS(DEFINE)
#undef DEFINE

template <i32 Mod>
std::ostream& operator<<(std::ostream& out, const ModInt<Mod>& m) {
  out << m.value();
  return out;
}

#endif
