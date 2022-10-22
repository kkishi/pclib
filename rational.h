#include <cstdint>
#include <numeric>
#include <ostream>

class Rational {
 public:
  Rational(int64_t n = 0, int64_t d = 1) : n_(n), d_(d) {
    if (d_ == 0) {
      n_ = 1;
      return;
    }
    if (n_ == 0) {
      d_ = 1;
      return;
    }
    int64_t g = std::gcd(n_, d_);
    n_ /= g;
    d_ /= g;
    if (d_ < 0) {
      n_ = -n_;
      d_ = -d_;
    }
  }
  bool operator<(const Rational& r) const { return n_ * r.d_ < r.n_ * d_; }
  bool operator<=(const Rational& r) const { return n_ * r.d_ <= r.n_ * d_; }
  bool operator==(const Rational& r) const { return n_ == r.n_ && d_ == r.d_; }
  int64_t n() const { return n_; }
  int64_t d() const { return d_; }
  std::pair<int64_t, int64_t> ToPair() const { return {n_, d_}; }

 private:
  int64_t n_, d_;
};

std::ostream& operator<<(std::ostream& out, const Rational& r) {
  out << r.n() << '/' << r.d();
  return out;
}
