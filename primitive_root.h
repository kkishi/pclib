#include <cstdint>
#include <iostream>

#include "divisors.h"
#include "pow.h"

bool IsPrimitiveRoot(int64_t r, int64_t p) {
  for (auto d : Divisors(p - 1)) {
    if (d != p - 1 && Pow(r, d, p) == 1) {
      return false;
    }
  }
  return true;
}
