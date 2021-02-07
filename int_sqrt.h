#include <cassert>

#include "binary_search.h"

template <typename T>
T IntSqrt(T x) {
  assert(x >= 0);
  T hi = std::max(x, x + 1);  // NOTE: x + 1 may overflow.
  return BinarySearch<T>(
      0, hi, [&](T y) { return !__builtin_mul_overflow(y, y, &y) && y <= x; });
}
