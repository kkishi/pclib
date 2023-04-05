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

// Returns the position of a point p relative to a convex hull P. This returns:
// * 0 if p is outside of P
// * 1 if p is inside of P
// * 2 if p is on the edge of P
// This is based on the algorithm described here:
// https://atcoder.jp/contests/abc296/editorial/6109
int ConvexHullPointPosition(const Polygon& P, Point p) {
  int n = P.size();
  auto cross = [&](Point a, Point b) { return Cross(b - a, p - a); };
  int c1 = cross(P[0], P[1]);
  int c2 = cross(P[n - 1], P[0]);
  if (c1 < 0 || c2 < 0) return 0;
  int i = BinarySearch<int>(n - 1, 1,
                            [&](int i) { return cross(P[0], P[i]) <= 0; });
  int c3 = cross(P[i - 1], P[i]);
  if (c3 < 0) return 0;
  if (c1 == 0 || c2 == 0 || c3 == 0) return 2;
  return 1;
}

#endif  // INT_GEOMETRY_H_
