#include <cstdint>
#include <numeric>
#include <ostream>
#include <utility>

class Rational : public std::pair<int64_t, int64_t> {
 public:
  using std::pair<int64_t, int64_t>::pair;  // Inherit constructors.
  void Normalize() {
    auto& [p, q] = *this;
    if (q == 0) {
      p = 0;
      return;
    }
    if (p == 0) {
      q = 1;
      return;
    }
    if (q < 0) {
      p = -p;
      q = -q;
    }
    int64_t g = std::gcd(p, q);
    p /= g;
    q /= g;
  }
  static Rational Normalized(int64_t p, int64_t q) {
    Rational r = {p, q};
    r.Normalize();
    return r;
  }
};

std::ostream& operator<<(std::ostream& out, const Rational& r) {
  out << r.first << '/' << r.second;
  return out;
}
