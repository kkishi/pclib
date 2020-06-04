#include <map>
#include <optional>
#include <queue>
#include <tuple>
#include <vector>

template <typename T>
class Grid {
  template <typename U>
  using pqueue = std::priority_queue<U, std::vector<U>, std::greater<U>>;

 public:
  Grid(int height, int width) : grid_(height, std::vector<T>(width)) {}
  void Set(int row, int col, T value) { grid_[row][col] = value; }
  std::optional<T> Distance(int src_row, int src_col, int dst_row,
                            int dst_col) {
    if (grid_[src_row][src_col] < 0) {
      return std::nullopt;
    }
    pqueue<std::tuple<T, int, int>> que;
    que.push({0, src_row, src_col});
    std::map<std::pair<int, int>, T> visited;
    visited[{src_row, src_col}] = 0;
    while (!que.empty()) {
      auto [dist, row, col] = que.top();
      que.pop();
      if (row == dst_row && col == dst_col) {
        return dist;
      }
      int dr[] = {1, -1, 0, 0};
      int dc[] = {0, 0, 1, -1};
      for (int i = 0; i < 4; ++i) {
        int nrow = row + dr[i];
        int ncol = col + dc[i];
        if (nrow < 0 || grid_.size() <= nrow || ncol < 0 ||
            grid_[0].size() <= ncol || grid_[nrow][ncol] < 0) {
          continue;
        }
        int ndist = dist + grid_[nrow][ncol];
        const auto it = visited.find({nrow, ncol});
        if (it != visited.end() && it->second <= ndist) {
          continue;
        }
        visited[{nrow, ncol}] = ndist;
        que.push({ndist, nrow, ncol});
      }
    }
    return std::nullopt;
  }

 private:
  std::vector<std::vector<T>> grid_;
};
