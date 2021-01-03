#include <functional>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

template <typename T>
class TreeDP {
 public:
  TreeDP(const std::vector<std::vector<int>>& edges, std::function<T(T, T)> op2,
         std::function<T(T)> op1, T identity = T())
      : edges_(edges), op2_(op2), op1_(op1), identity_(identity) {
    dp_.resize(edges.size());
    for (std::size_t i = 0; i < edges.size(); ++i) {
      dp_[i].resize(edges[i].size());
    }
    result_.resize(edges.size());
  }

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
        T t = identity_;
        for (std::size_t i = 0; i < edges_[node].size(); ++i) {
          if (int child = edges_[node][i]; child != parent) {
            t = op2_(t, dp_[node][i]);
          }
        }
        if (parent != -1) {
          dp_[parent][parent_index] = op1_(t);
        }
      }
    }
  }

  void Rerooting(int root) {
    std::stack<std::tuple<int, int, T>> s;
    s.push({root, -1, identity_});

    while (!s.empty()) {
      auto [node, parent, parent_result] = s.top();
      s.pop();

      const std::vector<int>& edges = edges_[node];
      std::vector<T>& dp = dp_[node];

      if (parent != -1) {
        for (std::size_t i = 0; i < edges.size(); ++i) {
          if (edges[i] == parent) {
            dp[i] = parent_result;
          }
        }
      }

      // lower[i] = op2_(dp[i - 1], op2_(dp[i - 2], ...))
      std::vector<T> lower(edges.size() + 1);
      lower[0] = identity_;
      for (std::size_t i = 0; i < edges.size(); ++i) {
        lower[i + 1] = op2_(lower[i], dp[i]);
      }

      // higher[i] = op2_(dp[i], op2_(dp[i + 1], ...))
      std::vector<T> higher(edges.size() + 1);
      higher[edges.size()] = identity_;
      for (std::size_t i = edges.size() - 1; i < edges.size(); --i) {
        higher[i] = op2_(higher[i + 1], dp[i]);
      }

      result_[node] = op1_(higher[0]);

      for (std::size_t i = 0; i < edges.size(); ++i) {
        if (int child = edges[i]; child != parent) {
          s.push({child, node, op1_(op2_(lower[i], higher[i + 1]))});
        }
      }
    }
  }

  const std::vector<std::vector<T>>& DP() const { return dp_; }
  const std::vector<T>& Result() const { return result_; }

 private:
  std::vector<std::vector<int>> edges_;

  const std::function<T(T, T)> op2_;
  const std::function<T(T)> op1_;
  const T identity_;

  std::vector<std::vector<T>> dp_;
  std::vector<T> result_;
};
