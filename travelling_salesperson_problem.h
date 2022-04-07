#include <cstdint>
#include <limits>
#include <optional>
#include <vector>

std::vector<std::vector<std::optional<int64_t>>> TravellingSalespersonProblem(
    const std::vector<std::vector<int64_t>>& dist, int64_t source = 0) {
  const int64_t n = dist.size();
  std::vector dp(1 << n, std::vector(n, std::optional<int64_t>()));
  dp[1 << source][source] = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int i = 0; i < n; ++i) {
      if (!((mask >> i) & 1)) continue;
      if (!dp[mask][i]) continue;
      for (int j = 0; j < n; ++j) {
        if ((mask >> j) & 1) continue;
        std::optional<int64_t>& x = dp[mask | (1 << j)][j];
        int64_t y = *dp[mask][i] + dist[i][j];
        if (!x || x > y) x = y;
      }
    }
  }
  return dp;
}
