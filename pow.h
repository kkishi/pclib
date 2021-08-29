#include <cstdint>

template <typename T>
constexpr T Pow(T b, int64_t e) {
  if (e < 0) return T(1) / Pow(b, -e);
  T x = 1;
  while (e > 0) {
    if (e & 1) x *= b;
    b *= b;
    e >>= 1;
  }
  return x;
}
