#include <cstdint>
#include <limits>
#include <vector>

template <typename T>
int64_t EditDistance(const T& a, const T& b, int64_t deletion = 1,
                     int64_t insertion = 1, int64_t substitution = 1) {
  int n = a.size(), m = b.size();
  std::vector dp(n + 1,
                 std::vector(m + 1, std::numeric_limits<int64_t>::max()));
  dp[0][0] = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      auto ch = [](int64_t& x, int64_t y) { x = std::min(x, y); };
      if (i < n && j < m) {
        ch(dp[i + 1][j + 1], dp[i][j] + (a[i] == b[j] ? 0 : substitution));
      }
      if (i < n) {
        ch(dp[i + 1][j], dp[i][j] + deletion);
      }
      if (j < m) {
        ch(dp[i][j + 1], dp[i][j] + insertion);
      }
    }
  }
  return dp[n][m];
}
