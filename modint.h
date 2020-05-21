#include <ostream>

template <int Mod>
class ModInt {
 public:
  ModInt() : n_(0) {}
  ModInt(long long n) : n_(n % Mod) {}
  ModInt& operator+=(const ModInt& m) {
    n_ += m.n_;
    if (n_ >= Mod) {
      n_ -= Mod;
    }
    return *this;
  }
  ModInt operator+(const ModInt& m) const { return ModInt(*this) += m; }
  ModInt& operator++() { return (*this) += 1; }
  ModInt& operator-=(const ModInt& m) {
    n_ -= m.n_;
    if (n_ < 0) {
      n_ += Mod;
    }
    return *this;
  }
  ModInt operator-(const ModInt& m) const { return ModInt(*this) -= m; }
  ModInt& operator--() { return (*this) -= 1; }
  ModInt& operator*=(const ModInt& m) {
    n_ *= m.n_;
    n_ %= Mod;
    return *this;
  }
  ModInt operator*(const ModInt& m) const { return ModInt(*this) *= m; }
  ModInt& operator/=(const ModInt& m) {
    *this *= m.inverse();
    return *this;
  }
  ModInt operator/(const ModInt& m) const { return ModInt(*this) /= m; }
  bool operator==(const ModInt& m) const { return n_ == m.n_; }
  ModInt pow(int n) const {
    if (n == 0) {
      return 1;
    }
    ModInt m = pow(n / 2);
    m *= m;
    if (n % 2 == 1) {
      m *= n_;
    }
    return m;
  }
  ModInt inverse() const {
    // Compute the inverse based on Fermat's little theorem. Note that this only
    // works when n_ and Mod are relatively prime. The theorem says that
    // n_^(Mod-1) = 1 (mod Mod). So we can compute n_^(Mod-2).
    return pow(Mod - 2);
  }
  long long value() const { return n_; }

 private:
  long long n_;
};

template <int Mod>
std::ostream& operator<<(std::ostream& out, const ModInt<Mod>& m) {
  out << m.value();
  return out;
}
