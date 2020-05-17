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
  ModInt operator+(const ModInt& m) const {
    ModInt n(*this);
    n += m;
    return n;
  }
  ModInt& operator++() {
    (*this) += 1;
    return *this;
  }
  ModInt& operator-=(const ModInt& m) {
    n_ -= m.n_;
    if (n_ < 0) {
      n_ += Mod;
    }
    return *this;
  }
  ModInt operator-(const ModInt& m) const {
    ModInt n(*this);
    n -= m;
    return n;
  }
  ModInt& operator*=(const ModInt& m) {
    n_ *= m.n_;
    n_ %= Mod;
    return *this;
  }
  ModInt operator*(const ModInt& m) const {
    ModInt n(*this);
    n *= m;
    return n;
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
