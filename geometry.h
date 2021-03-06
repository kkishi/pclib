#include <cmath>
#include <ostream>
#include <vector>

template <typename T>
struct Vector {
  T x = T(), y = T();
  T Norm() const { return std::sqrt(x * x + y * y); }
  Vector Conj() const { return {x, -y}; }
  T Real() const { return x; }
  T Imag() const { return y; }
  T Arg() const { return std::atan2(Imag(), Real()); }
  Vector& operator+=(const Vector& v) {
    (*this).x += v.x;
    (*this).y += v.y;
    return *this;
  }
  Vector operator+(const Vector& v) const { return Vector(*this) += v; }
  Vector& operator-=(const Vector& v) {
    (*this).x -= v.x;
    (*this).y -= v.y;
    return *this;
  }
  Vector operator-(const Vector& v) const { return Vector(*this) -= v; }
  Vector& operator*=(T t) {
    (*this).x *= t;
    (*this).y *= t;
    return *this;
  }
  Vector operator*(T t) const { return Vector(*this) *= t; }
  Vector& operator*=(const Vector& v) {
    T r = x * v.x - y * v.y;
    T i = x * v.y + y * v.x;
    (*this).x = r;
    (*this).y = i;
    return *this;
  }
  Vector operator*(const Vector& v) const { return Vector(*this) *= v; }
  Vector& operator/=(const Vector& v) {
    T q = v.x * v.x + v.y * v.y;
    assert(q != 0);
    T r = x * v.x + y * v.y;
    T i = x * v.y - y * v.x;
    (*this).x = r;
    (*this).y = i;
    return *this;
  }
  Vector operator/(const Vector& v) const { return Vector(*this) /= v; }
  bool operator<(const Vector& v) const {
    if (x != v.x) {
      return x < v.x;
    }
    return y < v.y;
  }
  Vector Rot90() const { return {-y, x}; }

  // TODO:
  // * Rename this struct to Point and add method that treats this struct as
  //   a 2D vector (e.g., dot product) and as a complex number (arc, multiple
  //   number multiplication, ...).
  //   Check the STL functions:
  //   https://ja.cppreference.com/w/cpp/numeric/complex Check the wikipedia
  //   page: https://en.wikipedia.org/wiki/Complex_number
  // * Replace Rot90 with more generic Rotate(arg) function.
  // * Think about a way to visualize these objects for debugging. One idea is
  //   to add an external library that renders these objects using Cairo.
  //   For visualization, WolframAlpha is also extremely useful, for example it
  //   even calculates intersections if provided 2 circles. Try:
  //   (x-1)^2+y^2=5^2, (x+7)^2+y^2=3^2
  // * Add common constants like pi.
};

template <typename T>
T Cross(const Vector<T>& a, const Vector<T>& b) {
  return (a.Conj() * b).Imag();
}

template <typename T>
std::istream& operator>>(std::istream& is, Vector<T>& v) {
  is >> v.x >> v.y;
  return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
  os << "(" << v.x << "," << v.y << ")";
  return os;
}

template <typename T>
struct LineSegment {
  Vector<T> a, b;
  bool Intersect(const LineSegment& l) {
    const double eps = 1e-8;
    return Cross(b - a, l.a - a) * Cross(b - a, l.b - a) < eps &&
           Cross(l.b - l.a, a - l.a) * Cross(l.b - l.a, b - l.a) < eps;
  }
};

template <typename T>
struct Circle {
  using V = Vector<T>;
  V center;
  double radius;

  std::vector<V> Intersections(const Circle& c) const {
    // TODO: Handle cases where there is no intersection and there is only one
    // intersection.
    auto sq = [](T x) -> T { return x * x; };
    V v = c.center - center;
    T l = v.Norm();
    if (l >= radius + c.radius || (l + radius) <= c.radius ||
        (l + c.radius) <= radius) {
      return {};
    }
    T x = (sq(radius) - sq(c.radius) + sq(l)) / (2 * l);
    T a = std::sqrt(sq(radius) - sq(x));
    V perpendicular_foot = v * (x / l);
    V perpendicular = v.Rot90() * (a / l);
    return {center + perpendicular_foot + perpendicular,
            center + perpendicular_foot - perpendicular};
  }

  // TODO: Add Contains method that checks if a point is contained in the
  // circle. That function should use EPS on check to take into account the
  // computation error. Proabbly this library should also provide a commom EPS
  // value (or provide utility functions that uses EPS inside of it).
};

const double pi = acos(-1);
