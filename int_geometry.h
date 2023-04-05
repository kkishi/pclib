#ifndef INT_GEOMETRY_H_
#define INT_GEOMETRY_H_

#include <complex>
#include <vector>

#include "binary_search.h"

struct Point {
  int64_t x, y;
};

Point& operator-=(Point& a, Point b) {
  a.x -= b.x;
  a.y -= b.y;
  return a;
}

Point operator-(Point a, Point b) { return a -= b; }

Point& operator+=(Point& a, Point b) {
  a.x += b.x;
  a.y += b.y;
  return a;
}

Point operator+(Point a, Point b) { return a += b; }

bool operator==(const Point& a, const Point& b) {
  return a.x == b.x && a.y == b.y;
}

std::istream& operator>>(std::istream& is, Point& p) {
  is >> p.x >> p.y;
  return is;
}

namespace std {
std::ostream& operator<<(std::ostream& os, Point p) {
  os << "(" << p.x << "," << p.y << ")";
  return os;
}
}  // namespace std

int64_t Cross(Point a, Point b) { return a.x * b.y - b.x * a.y; }
int64_t Dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
int64_t Norm(Point p) { return Dot(p, p); }

int CCW(Point a, Point b, Point c) {
  b -= a;
  c -= a;
  if (Cross(b, c) > 0) return 1;
  if (Cross(b, c) < 0) return -1;
  if (Dot(b, c) < 0) return 2;
  if (Norm(b) < Norm(c)) return -2;
  return 0;
}

Point Rot90(Point p) { return {-p.y, p.x}; }

struct Circle {
  Point c;
  int64_t r;
};

bool Intersects(const Circle& a, const Circle& b) {
  auto sq = [](int64_t x) { return x * x; };

  // Is a outside of b without an intersection?
  int64_t d2 = Norm(b.c - a.c);
  if (d2 > sq(a.r + b.r)) return false;

  // Does a contain b without an intersection?
  auto contains = [&](const Circle& a, const Circle& b) {
    return a.r > b.r && d2 < sq(a.r - b.r);
  };
  return !contains(a, b) && !contains(b, a);
}

using Polygon = std::vector<Point>;

int Contains(const Polygon& P, Point p) {
  int n = P.size();
  auto lof = [&](Point a, Point b) { return Cross(b - a, p - a) > 0; };
  auto rof = [&](Point a, Point b) { return Cross(b - a, p - a) < 0; };
  if (rof(P[0], P[1])) return 0;
  if (lof(P[0], P[n - 1])) return 0;
  int i = BinarySearch<int>(n - 1, 1, [&](int i) { return !lof(P[0], P[i]); });
  if (rof(P[i - 1], P[i])) return 0;
  auto on = [&](Point a, Point b) { return CCW(a, b, p) == 0; };
  if (on(P[0], P[1]) || on(P[i - 1], P[i]) || on(P[0], P[n - 1])) return 2;
  return 1;
}

#endif  // INT_GEOMETRY_H_
