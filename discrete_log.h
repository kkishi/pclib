#include "bsgs.h"

// Returns the minimum non-negative integer n that satisfies `x^n=y mod m`, or
// -1 if there's no such n.
int64_t DiscreteLog(int64_t x, int64_t y, int64_t m) {
  auto f = [&](int64_t a, int64_t b) { return a * b % m; };
  return BSGS<int64_t, int64_t>(x, 1 % m, y, m, f, f);
}
