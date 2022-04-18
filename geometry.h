#include <cmath>
#include <istream>
#include <ostream>
#include <vector>

#include "dassert.h"

using Float = long double;

struct Point {
  Float x = 0, y = 0;
  Float Norm() const { return std::sqrt(x * x + y * y); }
  Point Conj() const { return {x, -y}; }
  Float Real() const { return x; }
  Float Imag() const { return y; }
  Float Arg() const { return std::atan2(Imag(), Real()); }
  Point& operator+=(const Point& p) {
    this->x += p.x;
    this->y += p.y;
    return *this;
  }
  Point operator+(const Point& p) const { return Point(*this) += p; }
  Point& operator-=(const Point& p) {
    this->x -= p.x;
    this->y -= p.y;
    return *this;
  }
  Point operator-(const Point& p) const { return Point(*this) -= p; }
  Point operator-() const { return {-x, -y}; }
  Point& operator*=(Float t) {
    this->x *= t;
    this->y *= t;
    return *this;
  }
  Point operator*(Float t) const { return Point(*this) *= t; }
  Point& operator*=(const Point& p) {
    Float r = x * p.x - y * p.y;
    Float i = x * p.y + y * p.x;
    this->x = r;
    this->y = i;
    return *this;
  }
  Point operator*(const Point& p) const { return Point(*this) *= p; }
  Point& operator/=(Float t) {
    this->x /= t;
    this->y /= t;
    return *this;
  }
  Point operator/(Float t) const { return Point(*this) /= t; }
  Point& operator/=(const Point& p) {
    Float q = p.x * p.x + p.y * p.y;
    dassert(q != 0);
    Float r = x * p.x + y * p.y;
    Float i = x * p.y - y * p.x;
    this->x = r;
    this->y = i;
    return *this;
  }
  Point operator/(const Point& p) const { return Point(*this) /= p; }
  bool operator<(const Point& p) const {
    if (x != p.x) {
      return x < p.x;
    }
    return y < p.y;
  }
  Point Rot90() const { return {-y, x}; }
  static Point Polar(Float r, Float theta) {
    return Point{cos(theta), sin(theta)} *= r;
  }
};

Float Cross(const Point& p, const Point& q) { return p.x * q.y - p.y * q.x; }

std::istream& operator>>(std::istream& is, Point& p) {
  is >> p.x >> p.y;
  return is;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
  os << "(" << p.x << "," << p.y << ")";
  return os;
}

struct LineSegment {
  Point p, q;
};

struct Line {
  Point p, q;
};

std::ostream& operator<<(std::ostream& os, const Line& l) {
  os << "(" << l.p << "," << l.q << ")";
  return os;
}

int Sign(Float x) {
  const Float eps = 1e-9L;
  if (x < -eps) return -1;
  if (x > eps) return 1;
  return 0;
}

bool Intersect(const LineSegment& s, const LineSegment& t) {
  return Sign(Cross(s.q - s.p, t.p - s.p) * Cross(s.q - s.p, t.q - s.p)) <= 0 &&
         Sign(Cross(t.q - t.p, s.p - t.p) * Cross(t.q - t.p, s.q - t.p)) <= 0;
}

bool Intersect(const Line& l, const Point& p) {
  return Sign(Cross(l.p - p, l.q - p)) == 0;
};

struct Circle {
  Point center;
  Float radius;

  std::vector<Point> Intersections(const Circle& c) const {
    // TODO: Handle cases where there is no intersection and there is only one
    // intersection.
    auto sq = [](Float x) -> Float { return x * x; };
    Point p = c.center - center;
    Float l = p.Norm();
    if (l >= radius + c.radius || (l + radius) <= c.radius ||
        (l + c.radius) <= radius) {
      return {};
    }
    Float x = (sq(radius) - sq(c.radius) + sq(l)) / (2 * l);
    Float a = std::sqrt(sq(radius) - sq(x));
    Point perpendicular_foot = p * (x / l);
    Point perpendicular = p.Rot90() * (a / l);
    return {center + perpendicular_foot + perpendicular,
            center + perpendicular_foot - perpendicular};
  }

  // TODO: Add Contains method that checks if a point is contained in the
  // circle. That function should use EPS on check to take into account the
  // computation error. Proabbly this library should also provide a commom EPS
  // value (or provide utility functions that uses EPS inside of it).
};

const Float pi = 3.141592653589793238462643383279502884L;
