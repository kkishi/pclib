#include <functional>
#include <vector>

std::vector<std::vector<int>> StronglyConnectedComponents(
    const std::vector<std::vector<int>>& graph) {
  int n = graph.size();
  std::vector<int> nodes;
  std::vector<bool> visited(n);
  std::function<void(int)> dfs = [&](int u) {
    visited[u] = true;
    for (int v : graph[u]) {
      if (!visited[v]) {
        dfs(v);
      }
    }
    nodes.push_back(u);
  };
  for (int u = 0; u < n; ++u) {
    if (!visited[u]) dfs(u);
  }
  std::vector<std::vector<int>> rgraph(n);
  for (int u = 0; u < n; ++u) {
    for (int v : graph[u]) {
      rgraph[v].push_back(u);
    }
  }
  std::vector<bool> rvisited(n);
  std::vector<std::vector<int>> sccs;
  std::function<void(std::vector<int>&, int)> rdfs = [&](std::vector<int>& scc,
                                                         int u) {
    rvisited[u] = true;
    scc.push_back(u);
    for (int v : rgraph[u]) {
      if (!rvisited[v]) {
        rdfs(scc, v);
      }
    }
  };
  for (int i = n - 1; i >= 0; --i) {
    int u = nodes[i];
    if (!rvisited[u]) {
      std::vector<int> scc;
      rdfs(scc, u);
      sccs.push_back(scc);
    }
  }
  return sccs;
}
