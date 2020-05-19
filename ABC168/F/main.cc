#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

const int kMax = 1000;
int A[kMax];
int B[kMax];
int C[kMax];
int D[kMax];
int E[kMax];
int F[kMax];

typedef pair<int, int> Cell;

ostream& operator<<(ostream& os, const Cell& c) {
  cout << "{" << c.first << "," << c.second << "}";
  return os;
}

struct Content {
  bool online;
  bool visited;
};

class Grid {
 public:
  Grid(const set<int>& xs, const set<int>& ys) {
    xs_.push_back(*xs.begin() - 1);
    copy(xs.begin(), xs.end(), back_inserter(xs_));
    xs_.push_back(*xs.rbegin() + 1);

    REP(i, xs_.size()) xi_[xs_[i]] = i;

    ys_.push_back(*ys.begin() - 1);
    copy(ys.begin(), ys.end(), back_inserter(ys_));
    ys_.push_back(*ys.rbegin() + 1);

    REP(i, ys_.size()) yi_[ys_[i]] = i;

    grid_.resize(xs_.size() * 2 - 1);
    REP(i, grid_.size()) { grid_[i].resize(ys_.size() * 2 - 1); }
  }
  void DrawLineX(int x1, int x2, int y) {
    if (x1 > x2) swap(x1, x2);
    DrawLine(xi(x1), yi(y), xi(x2), yi(y), 1, 0);
  }
  void DrawLineY(int x, int y1, int y2) {
    if (y1 > y2) swap(y1, y2);
    DrawLine(xi(x), yi(y1), xi(x), yi(y2), 0, 1);
  }
  void DrawLine(int x, int y, int mx, int my, int dx, int dy) {
    for (; x <= mx && y <= my; x += dx, y += dy) {
      grid_[x][y].online = true;
    }
  }
  int xi(int x) const {
    auto it = xi_.find(x);
    assert(it != xi_.end());
    return it->second * 2;
  }
  int yi(int y) const {
    auto it = yi_.find(y);
    assert(it != yi_.end());
    return it->second * 2;
  }
  Cell CellAt(int lower_x, int lower_y) const {
    return {xi(lower_x) + 1, yi(lower_y) + 1};
  }
  void Debug() const {
    REP(i, grid_.size()) {
      REP(j, grid_[i].size()) { cout << grid_[i][j].online; }
      cout << endl;
    }
  }
  pair<Cell, bool> Move(const Cell& c, int dx, int dy) const {
    if (grid_[c.first + dx][c.second + dy].online) {
      return {{0, 0}, false};
    }
    return {{c.first + dx * 2, c.second + dy * 2}, true};
  };
  long long lower_x(const Cell& c) const { return xs_[c.first / 2]; }
  long long higher_x(const Cell& c) const { return xs_[(c.first + 1) / 2]; }
  long long lower_y(const Cell& c) const { return ys_[c.second / 2]; }
  long long higher_y(const Cell& c) const { return ys_[(c.second + 1) / 2]; }
  void DebugCell(const Cell& c) const {
    cout << "(" << lower_x(c) << "," << lower_y(c) << ") "
         << "(" << higher_x(c) << "," << higher_y(c) << ")" << endl;
  }
  long long AreaOf(const Cell& c) const {
    return (higher_x(c) - lower_x(c)) * (higher_y(c) - lower_y(c));
  }
  bool IsEdge(const Cell& c) const {
    return c.first == 1 || (c.first + 1) == (grid_.size() - 1) ||
           c.second == 1 || (c.second + 1) == (grid_[0].size() - 1);
  };
  bool Visited(const Cell& c) const { return grid_[c.first][c.second].visited; }
  void Visit(const Cell& c) { grid_[c.first][c.second].visited = true; }

 private:
  vector<int> xs_, ys_;
  map<int, int> xi_, yi_;

  vector<vector<Content>> grid_;
};

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void GridTest() {
  set<int> xs;
  xs.insert(0);
  xs.insert(-1);
  xs.insert(1);
  set<int> ys;
  ys.insert(0);
  ys.insert(1);
  Grid grid(xs, ys);
  grid.DrawLineX(-1, 1, 1);
  grid.Debug();
  Cell center = grid.CellAt(0, 0);
  cout << grid.IsEdge(center) << endl;
  cout << center.first << " " << center.second << endl;
  Cell right;
  bool ok;
  tie(right, ok) = grid.Move(center, 0, 1);
  cout << "ok:" << ok << endl;
  cout << grid.IsEdge(right) << endl;
  cout << right.first << " " << right.second << endl;
  cout << "area" << endl;
  cout << grid.AreaOf(center) << endl;
  cout << grid.lower_x(center) << " " << grid.lower_y(center) << endl;
  cout << grid.higher_x(center) << " " << grid.higher_y(center) << endl;
}

int main() {
  // GridTest();
  // return 0;

  int N, M;
  cin >> N >> M;
  REP(i, N) cin >> A[i] >> B[i] >> C[i];
  REP(i, M) cin >> D[i] >> E[i] >> F[i];

  set<int> xs;
  set<int> ys;
  REP(i, N) {
    xs.insert(A[i]);
    xs.insert(B[i]);
    ys.insert(C[i]);
  }
  REP(i, M) {
    xs.insert(D[i]);
    ys.insert(E[i]);
    ys.insert(F[i]);
  }
  xs.insert(0);
  ys.insert(0);

  Grid grid(xs, ys);

  REP(i, N) grid.DrawLineX(A[i], B[i], C[i]);
  REP(i, M) grid.DrawLineY(D[i], E[i], F[i]);

  // grid.Debug();

  Cell init = grid.CellAt(0, 0);

  queue<Cell> que;
  que.push(init);

  grid.Visit(init);
  /*
  vector<vector<bool>> visited(grid.grid_x_ / 2 + 10);
  REP(i, visited.size()) visited[i].resize(grid.grid_y_ / 2 + 10);
  visited[init.first / 2][init.second / 2] = true;
  */

  long long ans = 0;
  while (!que.empty()) {
    Cell here = que.front();
    que.pop();

    // cout << here << endl;
    // grid.DebugCell(here);

    if (grid.IsEdge(here)) {
      ans = -1;
      break;
    }
    ans += grid.AreaOf(here);
    REP(i, 4) {
      auto [there, ok] = grid.Move(here, dx[i], dy[i]);
      if (!ok) {
        continue;
      }
      if (grid.Visited(there)) {
        continue;
      }
      grid.Visit(there);
      que.push(there);
    }
  }
  if (ans == -1) {
    cout << "INF" << endl;
  } else {
    cout << ans << endl;
  }
}
