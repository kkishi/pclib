#include <numeric>
#include <ostream>

#include "dassert.h"

template <typename T>
class Rational {
 public:
  Rational(T p, T q) {
    dassert(q != 0);
    if (p == 0) {
      p_ = 0;
      q_ = 1;
      return;
    }
    if (q < 0) {
      p = -p;
      q = -q;
    }
    T sign = 1;
    if (p < 0) {
      sign = -1;
      p = -p;
    }
    T g = std::gcd(p, q);
    p_ = sign * (p / g);
    q_ = q / g;
  }
  T p() const { return p_; }
  T q() const { return q_; }

 private:
  T p_;
  T q_;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Rational<T>& r) {
  out << r.p() << '/' << r.q();
  return out;
}
