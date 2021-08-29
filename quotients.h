#include <cstdint>
#include <vector>

// Returns a value that is equivalent to:
//
// map<int, int> cnt;
// for (int i = 1; i <= x; ++i) ++cnt[x / i];
// return cnt;
//
// Note that the return value is not sorted in any way.
std::vector<std::pair<int64_t, int64_t>> Quotients(int64_t x) {
  std::vector<std::pair<int64_t, int64_t>> v;
  for (int64_t d = 1; d * d <= x; ++d) {
    int64_t q = x / d;
    v.emplace_back(q, 1);
    if (q > d) {
      int64_t Q = x / (d + 1);
      v.emplace_back(d, q - Q);
    }
  }
  return v;
}
