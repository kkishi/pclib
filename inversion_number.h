#include <cstdint>
#include <vector>

#include "bit.h"
#include "compressor.h"

int64_t InversionNumber(const std::vector<int64_t>& v) {
  Compressor c(v);
  BIT<int64_t> b(c.coord.size());
  int64_t ret = 0;
  for (size_t i = 0; i < v.size(); ++i) {
    int64_t x = c(v[i]);
    b.Add(x, 1);
    ret += i + 1 - b.Sum(x);
  }
  return ret;
}
