#include <stack>

#include "dassert.h"
#include "graph.h"

std::pair<std::vector<int>, std::vector<int>> EulerTour(const Graph& g,
                                                        int root = 0) {
  dassert(g.IsTree());
  const int n = g.size();
  std::vector<int> in(n, -1), out(n);
  int idx = 0;
  std::stack<int> st;
  st.push(root);
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    if (in[u] == -1) {
      in[u] = idx++;
      st.push(u);
      for (int v : g[u]) {
        if (in[v] == -1) st.push(v);
      }
    } else {
      out[u] = idx;
    }
  }
  return {in, out};
}
