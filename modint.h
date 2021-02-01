#include <cassert>
#include <ostream>
#include <vector>

#define BIN_OPS(F) F(+) F(-) F(*) F(/)
#define CMP_OPS(F) F(!=) F(<) F(<=) F(==) F(>) F(>=)

template <int Mod = 1000000007>
class ModInt {
 public:
  ModInt() : n_(0) {}
  ModInt(long long n) : n_(n % Mod) {
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
    n_ *= m.n_;
    n_ %= Mod;
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
  ModInt Pow(int n) const {
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
    assert(n_ != 0);
    if (n_ > 1000000) {
      // Compute the inverse based on Fermat's little theorem. Note that this
      // only works when n_ and Mod are relatively prime. The theorem says that
      // n_^(Mod-1) = 1 (mod Mod). So we can compute n_^(Mod-2).
      return Pow(Mod - 2);
    }
    for (int i = inv_.size(); i <= n_; ++i) {
      inv_.push_back(i <= 1 ? i : (Mod / i * -inv_[Mod % i]));
    }
    return inv_[n_];
  }
  long long value() const { return n_; }

  static ModInt Fact(int n) {
    for (int i = fact_.size(); i <= n; ++i) {
      fact_.push_back(i == 0 ? 1 : fact_.back() * i);
    }
    return fact_[n];
  }
  static ModInt Comb(int n, int k) { return Perm(n, k) / Fact(k); }
  static ModInt CombSlow(int n, int k) { return PermSlow(n, k) / Fact(k); }
  static ModInt Perm(int n, int k) {
#if DEBUG
    assert(n <= 1000000 &&
           "n is too large. If k is small, consider using PermSlow.");
#endif
    return Fact(n) / Fact(n - k);
  }
  static ModInt PermSlow(int n, int k) {
    ModInt p = 1;
    for (int i = 0; i < k; ++i) {
      p *= (n - i);
    }
    return p;
  }

 private:
  long long n_;
  inline static std::vector<ModInt> fact_;
  inline static std::vector<ModInt> inv_;
};

#define DEFINE(op)                                            \
  template <int Mod, typename T>                              \
  ModInt<Mod> operator op(const T& t, const ModInt<Mod>& m) { \
    return ModInt<Mod>(t) op m;                               \
  }
BIN_OPS(DEFINE)
CMP_OPS(DEFINE)
#undef DEFINE

template <int Mod>
std::ostream& operator<<(std::ostream& out, const ModInt<Mod>& m) {
  out << m.value();
  return out;
}
