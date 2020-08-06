#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"
#include "rerooting.h"

using namespace std;

using mint = ModInt<1000000000 + 7>;

struct DP {
  int size;
  mint cnt;
  mint fact;
};

DP Combine(DP a, DP b) {
  return {a.size + b.size, a.cnt * b.cnt, a.fact * b.fact};
}

DP Calc(DP x) {
  return {x.size + 1, x.cnt / x.fact * mint::Fact(x.size),
          mint::Fact(x.size + 1)};
}

int main() {
  rd(int, N);

  vector<vector<int>> edges(N);
  rep(i, N - 1) {
    rd(int, a, b);
    --a, --b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  TreeDP<DP> tdp(edges, Combine, Calc, {0, 1, 1});
  tdp.DFS(0);
  tdp.Rerooting(0);
  rep(i, N) wt(tdp.Result()[i].cnt);
}
