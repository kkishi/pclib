#include <algorithm>
#include <vector>

struct Compressor {
  Compressor(const std::vector<int64_t>& v) : coord(v) {
    std::sort(coord.begin(), coord.end());
    coord.erase(std::unique(coord.begin(), coord.end()), coord.end());
  }
  int64_t operator()(int64_t x) const {
    return std::lower_bound(coord.begin(), coord.end(), x) - coord.begin();
  }
  std::vector<int64_t> coord;
};
