#include <cstdint>
#include <vector>

std::vector<int64_t> Totient(int64_t n) {
  std::vector<int64_t> v(n + 1);
  for (int64_t i = 1; i <= n; ++i) {
    v[i] = i;
  }
  for (int64_t i = 2; i <= n; ++i) {
    if (v[i] == i) {
      for (int64_t j = i; j <= n; j += i) {
        v[j] = v[j] / i * (i - 1);
      }
    }
  }
  return v;
}
