#include <cmath>
#include <ostream>
#include <vector>

template <typename T>
struct Vector {
  T x, y;
  T Norm() const { return std::sqrt(x * x + y * y); }
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
  Vector Rot90() const { return {-y, x}; }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
  os << "(" << v.x << "," << v.y << ")";
  return os;
}

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
    T x = (sq(radius) - sq(c.radius) + sq(l)) / (2 * l);
    T a = std::sqrt(sq(c.radius) - sq(x));
    V perpendicular_foot = v * (x / l);
    V perpendicular = v.Rot90() * (a / l);
    return {perpendicular_foot + perpendicular,
            perpendicular_foot - perpendicular};
  }
};
