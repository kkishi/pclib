#ifndef POW_H_
#define POW_H_

#include <cstdint>

constexpr int64_t Pow(int64_t b, int64_t e, int64_t m = 0) {
  __int128_t x = 1, y = b;
  while (e > 0) {
    if (e & 1) {
      x *= y;
      if (m) x %= m;
    }
    y *= y;
    if (m) y %= m;
    e >>= 1;
  }
  return x;
}

#endif  // POW_H_
