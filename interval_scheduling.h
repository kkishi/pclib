#include <algorithm>
#include <cstdint>
#include <vector>

// Each element of the input represents an interval [first, second).
int64_t IntervalScheduling(const std::vector<std::pair<int64_t, int64_t>>& v) {
  std::vector<std::pair<int64_t, int64_t>> w;
  for (auto [l, r] : v) w.emplace_back(r, l);
  std::sort(w.begin(), w.end());
  int64_t last_r = std::numeric_limits<int64_t>::min();
  int64_t ret = 0;
  for (auto [r, l] : w) {
    if (last_r <= l) {
      last_r = r;
      ++ret;
    }
  }
  return ret;
}
