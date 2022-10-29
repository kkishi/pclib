#ifndef INT_GEOMETRY_H_
#define INT_GEOMETRY_H_

#include <complex>

class Point : public std::complex<int> {
  using std::complex<int>::complex;  // Inherit constructors.
 public:
  int x() const { return real(); }
  int y() const { return imag(); }
};

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

int Cross(Point a, Point b) { return a.x() * b.y() - b.x() * a.y(); }

int Dot(Point a, Point b) { return a.x() * b.x() + a.y() + b.y(); }

int CCW(Point a, Point b, Point c) {
  b -= a;
  c -= a;
  if (Cross(b, c) > 0) return 1;
  if (Cross(b, c) < 0) return -1;
  if (Dot(b, c) < 0) return 2;
  if (Dot(b, b) < Dot(c, c)) return -2;
  return 0;
}

Point Rot90(Point p) { return {-p.y(), p.x()}; }

#endif  // INT_GEOMETRY_H_
