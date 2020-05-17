#include <ostream>

#include "gcd.h"

template <typename T>
class Rational {
 public:
  Rational(T numerator, T denominator) {
    assert(denominator != 0);
    if (numerator == 0) {
      numerator_ = 0;
      denominator_ = 1;
      return;
    }
    if (denominator < 0) {
      numerator = -numerator;
      denominator = -denominator;
    }
    T sign = 1;
    if (numerator < 0) {
      sign = -1;
      numerator = -numerator;
    }
    T gcd = Gcd(numerator, denominator);
    numerator_ = sign * (numerator / gcd);
    denominator_ = denominator / gcd;
  }
  T numerator() const { return numerator_; }
  T denominator() const { return denominator_; }

 private:
  T numerator_;
  T denominator_;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Rational<T>& r) {
  out << r.numerator() << '/' << r.denominator();
  return out;
}
