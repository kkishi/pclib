#include <bits/stdc++.h>

#include "bound_grid.h"
#include "compress.h"
#include "macros.h"

using namespace std;

const int kMax = 1000;
int A[kMax];
int B[kMax];
int C[kMax];
int D[kMax];
int E[kMax];
int F[kMax];

struct GridState {
  bool online;
  bool visited;
};

using Grid = BoundGrid<GridState>;

void DrawLineX(Grid& g, int x1, int x2, int y) {
  if (x1 > x2) swap(x1, x2);
  for (int x = x1; x < x2; ++x) {
    g.Boundary({x, y}, 0, -1).online = true;
  }
}

void DrawLineY(Grid& g, int x, int y1, int y2) {
  if (y1 > y2) swap(y1, y2);
  for (int y = y1; y < y2; ++y) {
    g.Boundary({x, y}, -1, 0).online = true;
  }
}

void Debug(const Grid& g) {
  auto to_char = [](const GridState& s, optional<char> boundary) -> char {
    if (boundary) {
      return s.online ? *boundary : ' ';
    }
    return s.visited ? 'o' : ' ';
  };
  g.Debug(cerr, to_char);
}

int main() {
  rd(int, N, M);

  rep(i, N) cin >> A[i] >> B[i] >> C[i];
  rep(i, M) cin >> D[i] >> E[i] >> F[i];

  set<int> xs;
  set<int> ys;

  xs.insert(A, A + N);
  xs.insert(B, B + N);
  ys.insert(C, C + N);
  xs.insert(D, D + M);
  ys.insert(E, E + M);
  ys.insert(F, F + M);

  xs.insert(0);
  xs.insert(*xs.begin() - 1);
  xs.insert(*xs.rbegin() + 1);
  ys.insert(0);
  ys.insert(*ys.begin() - 1);
  ys.insert(*ys.rbegin() + 1);

  vector cx = Compress(vector(all(xs)));
  vector cy = Compress(vector(all(ys)));
  auto xi = Uncompressor(cx);
  auto yi = Uncompressor(cy);

  Grid grid(cx.size() - 1, cy.size() - 1);

  rep(i, N) DrawLineX(grid, xi(A[i]), xi(B[i]), yi(C[i]));
  rep(i, M) DrawLineY(grid, xi(D[i]), yi(E[i]), yi(F[i]));

  Coord init = {xi(0), yi(0)};

  queue<Coord> que;
  que.push(init);

  grid.StateOf(init).visited = true;

  long long ans = 0;
  while (!que.empty()) {
    Coord here = que.front();
    que.pop();
    long long x = cx[here.x + 1] - cx[here.x];
    long long y = cy[here.y + 1] - cy[here.y];
    ans += x * y;
    rep(i, 4) {
      int dx[] = {0, 1, 0, -1};
      int dy[] = {1, 0, -1, 0};
      if (grid.Boundary(here, dx[i], dy[i]).online) {
        continue;
      }
      Coord there = {here.x + dx[i], here.y + dy[i]};
      if (!grid.InBounds(there)) {
        cout << "INF" << endl;
        return 0;
      }
      GridState& s = grid.StateOf(there);
      if (s.visited) {
        continue;
      }
      s.visited = true;
      que.push(there);
    }
  }
  // Debug(grid);
  wt(ans);
}
