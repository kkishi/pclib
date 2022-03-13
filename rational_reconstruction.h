#include <array>

#include "modint.h"

// https://github.com/catupper/RationalModConverter
template <i32 Mod>
std::pair<i64, i64> RationalReconstruction(const ModInt<Mod>& n) {
  i64 v0 = Mod, v1 = 0;
  i64 w0 = n.value(), w1 = 1;
  while (w0 * w0 * 2 > Mod) {
    i64 q = v0 / w0;
    i64 z0 = v0 - q * w0;
    i64 z1 = v1 - q * w1;
    v0 = w0;
    v1 = w1;
    w0 = z0;
    w1 = z1;
  }
  if (w1 < 0) {
    w0 *= -1;
    w1 *= -1;
  }
  return {w0, w1};
}
