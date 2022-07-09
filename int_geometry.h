#ifndef INT_GEOMETRY_H_
#define INT_GEOMETRY_H_

#include <complex>

using Point = std::complex<int>;

std::istream& operator>>(std::istream& is, Point& p) {
  int x, y;
  is >> x >> y;
  p = {x, y};
  return is;
}

struct Circle {
  Point c;
  int r;
};

bool Intersects(const Circle& a, const Circle& b) {
  auto sq = [](int x) { return x * x; };

  // Is a outside of b without an intersection?
  int d2 = norm(b.c - a.c);
  if (d2 > sq(a.r + b.r)) return false;

  // Does a contain b without an intersection?
  auto contains = [&](const Circle& a, const Circle& b) {
    return a.r > b.r && d2 < sq(a.r - b.r);
  };
  return !contains(a, b) && !contains(b, a);
}

#endif  // INT_GEOMETRY_H_
