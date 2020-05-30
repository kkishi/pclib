#include <stack>
#include <tuple>
#include <utility>
#include <vector>

template <typename T, T Op1(T, T), T Op2(T)>
class TreeDP {
 public:
  TreeDP(const std::vector<std::vector<int>>& edges) : edges_(edges) {
    dp_.resize(edges.size());
    for (std::size_t i = 0; i < edges.size(); ++i) {
      dp_[i].resize(edges[i].size());
    }
    result_.resize(edges.size());
  }

  // TODO: Pass this via a constructor.
  void SetUnit(const T& unit) { unit_ = unit; }

  void DFS(int root) {
    // Use a stack to avoid potential stack overflows.
    std::stack<std::tuple<int, int, int, bool>> s;
    s.push({root, -1, -1, true});

    while (!s.empty()) {
      auto [node, parent, parent_index, enter] = s.top();
      s.pop();

      if (enter) {
        s.push({node, parent, parent_index, false});
        for (std::size_t i = 0; i < edges_[node].size(); ++i) {
          if (int child = edges_[node][i]; child != parent) {
            s.push({child, node, i, true});
          }
        }
      } else {
        T t = unit_;
        for (std::size_t i = 0; i < edges_[node].size(); ++i) {
          if (int child = edges_[node][i]; child != parent) {
            t = Op1(t, dp_[node][i]);
          }
        }
        if (parent != -1) {
          dp_[parent][parent_index] = Op2(t);
        }
      }
    }
  }

  void Rerooting(int root) {
    std::stack<std::tuple<int, int, T>> s;
    s.push({root, -1, unit_});

    while (!s.empty()) {
      auto [node, parent, parent_result] = s.top();
      s.pop();

      const std::vector<int> edges = edges_[node];
      std::vector<T>& dp = dp_[node];

      if (parent != -1) {
        for (std::size_t i = 0; i < edges.size(); ++i) {
          if (edges[i] == parent) {
            dp[i] = parent_result;
          }
        }
      }

      // lower[i] = Op1(dp[i - 1], Op1(dp[i - 2], ...))
      std::vector<T> lower(edges.size() + 1);
      lower[0] = unit_;
      for (std::size_t i = 0; i < edges.size(); ++i) {
        lower[i + 1] = Op1(lower[i], dp[i]);
      }

      // higher[i] = Op1(dp[i], Op1(dp[i + 1], ...))
      std::vector<T> higher(edges.size() + 1);
      higher[edges.size()] = unit_;
      for (std::size_t i = edges.size() - 1; i < edges.size(); --i) {
        higher[i] = Op1(higher[i + 1], dp[i]);
      }

      result_[node] = Op2(higher[0]);

      for (std::size_t i = 0; i < edges.size(); ++i) {
        if (int child = edges[i]; child != parent) {
          s.push({child, node, Op2(Op1(lower[i], higher[i + 1]))});
        }
      }
    }
  }

  const std::vector<std::vector<T>>& DP() const { return dp_; }
  const std::vector<T>& Result() const { return result_; }

 private:
  T unit_ = T();
  std::vector<std::vector<int>> edges_;
  std::vector<std::vector<T>> dp_;
  std::vector<T> result_;
};
