#include "disjoint_set.h"
#include "graph.h"

template <typename T>
int64_t Kruskal(const WeightedGraph<T>& g) {
  const int n = g.size();
  std::vector<std::tuple<T, int64_t, int64_t>> v;
  for (int i = 0; i < n; ++i) {
    for (auto [j, w] : g[i]) {
      if (i < j) v.emplace_back(w, i, j);
    }
  }
  sort(v.begin(), v.end());
  DisjointSet ds(n);
  T ret = 0;
  for (auto [w, i, j] : v) {
    if (ds.Union(i, j)) ret += w;
  }
  return ret;
}
