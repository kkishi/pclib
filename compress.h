#include <algorithm>
#include <vector>

class Compressor : public std::vector<int64_t> {
 public:
  Compressor(const std::vector<int64_t>& v) : std::vector<int64_t>(v) {
    std::sort(begin(), end());
    erase(std::unique(begin(), end()), end());
  }
  int64_t operator()(int64_t x) const {
    return std::lower_bound(begin(), end(), x) - begin();
  }
};
