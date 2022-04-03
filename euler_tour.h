#include <stack>

#include "dassert.h"
#include "graph.h"

template <typename T>
std::pair<std::vector<int>, std::vector<int>> EulerTour(const Graph<T>& g,
                                                        int root = 0) {
  dassert(g.IsTree());
  const int n = g.NumVertices();
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
      for (const auto& e : g.Edges(u))
        if (in[e.to] == -1) st.push(e.to);
    } else {
      out[u] = idx;
    }
  }
  return {in, out};
}
