#include <bits/stdc++.h>

#include "macros.h"
#include "segment_tree.h"

int main() {
  CIN(int, N);
  SegmentTree<int> tree(N, [](int a, int b) { return a | b; });
  string S;
  cin >> S;
  REP(i, N) tree.Set(i, 1 << (S[i] - 'a'));
  REP(i, N) DBG(i, tree.Get(i));
  int Q;
  cin >> Q;
  REP(q, Q) {
    int t;
    cin >> t;
    if (t == 1) {
      int i;
      char c;
      cin >> i >> c;
      tree.Set(i - 1, 1 << (c - 'a'));
    } else {
      int l, r;
      cin >> l >> r;
      cout << __builtin_popcount(tree.Aggregate(l - 1, r)) << endl;
    }
  }
}
