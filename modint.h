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
  long long value() const { return n_; }

 private:
  long long n_;
};

template <int Mod>
std::ostream& operator<<(std::ostream& out, const ModInt<Mod>& m) {
  out << m.value();
  return out;
}
