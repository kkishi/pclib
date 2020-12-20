#include <utility>

template <typename T>
T Gcd(T a, T b) {
  if (b == 0) {
    return a;
  }
  return Gcd(b, a % b);
}

// auto [g, x, y] = ExtGcd(a, b);
// => a * x + b * y = g = gcd(a, b)
template <typename T>
std::tuple<T, T, T> ExtGcd(T a, T b) {
  if (b == 0) {
    return {a, 1, 0};
  }
  auto [g, x, y] = ExtGcd(b, a % b);
  return {g, y, x - (a / b) * y};
}
