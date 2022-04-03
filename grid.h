#include <map>
#include <optional>
#include <queue>
#include <tuple>
#include <vector>

#include "dassert.h"

template <typename T>
class Grid {
  template <typename U>
  using pqueue = std::priority_queue<U, std::vector<U>, std::greater<U>>;
  using grid = std::vector<std::vector<std::optional<T>>>;

 public:
  Grid(int r, int c)
      : r_(r), c_(c), grid_(r, std::vector<std::optional<T>>(c)) {}
  bool Inside(int r, int c) const {
    return 0 <= r && r < r_ && 0 <= c && c < c_;
  }
  void Set(int r, int c, T v) {
    dassert(Inside(r, c));
    grid_[r][c] = v;
  }
  grid Distance(int sr, int sc) const {
    dassert(Inside(sr, sc));
    dassert(grid_[sr][sc]);
    pqueue<std::tuple<T, int, int>> que;
    que.emplace(0, sr, sc);
    grid dist(r_, std::vector<std::optional<T>>(c_));
    dist[sr][sc] = 0;
    while (!que.empty()) {
      auto [d, r, c] = que.top();
      que.pop();
      for (int i = 0; i < 4; ++i) {
        const int dr[] = {1, -1, 0, 0};
        const int dc[] = {0, 0, 1, -1};
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (!Inside(nr, nc) || !grid_[nr][nc]) {
          continue;
        }
        T nd = d + *grid_[nr][nc];
        std::optional<T>& di = dist[nr][nc];
        if (di && *di <= nd) {
          continue;
        }
        di = nd;
        que.emplace(nd, nr, nc);
      }
    }
    return dist;
  }

 private:
  const int r_, c_;
  grid grid_;
};
