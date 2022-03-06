#include <math.h>

#include <numeric>
#include <vector>

template <typename Add, typename Del, typename Get>
std::vector<int64_t> Mo(
    Add add, Del del, Get get,
    const std::vector<std::pair<int64_t, int64_t>>& queries) {
  using Range = std::pair<int64_t, int64_t>;  // [first, second)

  const int n = queries.size();
  std::vector<int32_t> idx(n);
  std::iota(idx.begin(), idx.end(), 0);

  const int32_t bin = sqrt(n);
  sort(idx.begin(), idx.end(), [&](int32_t ai, int32_t bi) {
    const Range &a = queries[ai], &b = queries[bi];
    int32_t c = a.first / bin, d = b.first / bin;
    if (c != d) return c < d;
    if (c % 2 == 0) {
      return a.second < b.second;
    }
    return a.second > b.second;
  });

  std::vector<int64_t> ret(n);
  Range p = {0, 0};
  for (int i : idx) {
    const Range& c = queries[i];
    auto range = [&](auto fun, int begin, int end) {
      for (int i = begin; i < end; ++i) {
        fun(i);
      }
    };
    range(add, c.first, p.first);
    range(del, p.first, c.first);
    range(add, p.second, c.second);
    range(del, c.second, p.second);
    ret[i] = get();
    p = c;
  }
  return ret;
}
