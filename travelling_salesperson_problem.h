#include <cstdint>
#include <vector>

void TravellingSalespersonProblem(
    std::vector<std::vector<int64_t>>& dp,
    const std::vector<std::vector<int64_t>>& dist) {
  const int64_t n = dist.size();
  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int i = 0; i < n; ++i) {
      if (!((mask >> i) & 1)) continue;
      for (int j = 0; j < n; ++j) {
        if ((mask >> j) & 1) continue;
        int64_t& x = dp[mask | (1 << j)][j];
        int64_t y = dp[mask][i] + dist[i][j];
        if (x > y) x = y;
      }
    }
  }
}
