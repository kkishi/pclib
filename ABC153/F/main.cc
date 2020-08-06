#include <bits/stdc++.h>

#include "dual_segment_tree.h"
#include "macros.h"

using namespace std;

struct Monster {
  ll X, H;
  bool operator<(const Monster& m) const { return X < m.X; }
};

Monster monster[200000];

int main() {
  rd(ll, N, D, A);
  rep(i, N) cin >> monster[i].X >> monster[i].H;
  sort(monster, monster + N);

  DualSegmentTree<ll> tree(N, [](ll a, ll b) { return a + b; });
  rep(i, N) tree.Update(i, i + 1, monster[i].H);

  ll ans = 0;
  int mi = 0;
  while (mi < N) {
    int h = tree.Get(mi);
    if (h <= 0) {
      ++mi;
      continue;
    }
    Monster max_m = {monster[mi].X + D * 2, 0};
    int ub = upper_bound(monster, monster + N, max_m) - monster;
    ll cnt = (h + A - 1) / A;
    tree.Update(mi, ub, -cnt * A);
    ans += cnt;
  }
  wt(ans);
}
