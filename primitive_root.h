#include <cstdint>

bool IsPrimitiveRoot(int64_t r, int64_t p) {
  auto ok = [&](int64_t e) {
    // Check if r^e==1.
    __int128_t x = 1, b = r;
    while (e > 0) {
      if (e & 1) x = x * b % p;
      b = b * b % p;
      e >>= 1;
    }
    return x != 1;
  };
  int64_t q = p - 1;
  for (int64_t i = 2; i * i <= q; ++i) {
    if (q % i == 0 && (!ok(i) || !ok(q / i))) return false;
  }
  return true;
}
