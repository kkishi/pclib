#include <cstdint>
#include <vector>

// Returns a value that is equivalent to:
//
// map<int, int> cnt;
// for (int i = 1; i <= x; ++i) ++cnt[x / i];
// return cnt;
//
// The return value is sorted in descending order.
//
// The algorithm is based on: https://youtu.be/ZrSO7fB7nlA?t=5034
std::vector<std::pair<int64_t, int64_t>> Quotients(int64_t x) {
  std::vector<std::pair<int64_t, int64_t>> v;
  for (int64_t i = 1; i <= x;) {
    int64_t q = x / i;
    int64_t j = x / q + 1;
    v.emplace_back(q, j - i);
    i = j;
  }
  return v;
}
