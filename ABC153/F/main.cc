#include <bits/stdc++.h>

#include "macros.h"
#include "segment_tree.h"

using namespace std;

using ll = long long;

struct Monster {
  ll X, H;
  bool operator<(const Monster& m) const { return X < m.X; }
};

Monster monster[200000];

int main() {
  CIN(ll, N, D, A);
  REP(i, N) cin >> monster[i].X >> monster[i].H;
  sort(monster, monster + N);

  RangeSegmentTree tree = AdditiveSegmentTree<ll>(N);
  REP(i, N) tree.Apply(i, i + 1, monster[i].H);

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
    tree.Apply(mi, ub, -cnt * A);
    ans += cnt;
  }
  COUT(ans);
}