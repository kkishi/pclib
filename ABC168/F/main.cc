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

template <typename T>
vector<T> Compress(vector<T> v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  return v;
}

template <typename T>
T Index(const vector<T>& v, T x) {
  return lower_bound(v.begin(), v.end(), x) - v.begin();
}

struct Coord {
  int x, y;
};

ostream& operator<<(ostream& os, const Coord& c) {
  cout << "{" << c.x << "," << c.y << "}";
  return os;
}

struct State {
  bool online;
  bool visited;
};

class Grid {
 public:
  Grid(int x, int y) {
    grid_.resize(x * 2 - 1);
    REP(i, grid_.size()) grid_[i].resize(y * 2 - 1);
  }
  void DrawLineX(int x1, int x2, int y) {
    if (x1 > x2) swap(x1, x2);
    DrawLine(x1 * 2, y * 2, x2 * 2, y * 2, 1, 0);
  }
  void DrawLineY(int x, int y1, int y2) {
    if (y1 > y2) swap(y1, y2);
    DrawLine(x * 2, y1 * 2, x * 2, y2 * 2, 0, 1);
  }
  void DrawLine(int x, int y, int mx, int my, int dx, int dy) {
    for (; x <= mx && y <= my; x += dx, y += dy) {
      state({x, y}).online = true;
    }
  }
  Coord At(int lower_x, int lower_y) const {
    return {lower_x * 2 + 1, lower_y * 2 + 1};
  }
  void Debug() const {
    REP(i, grid_.size()) {
      REP(j, grid_[i].size()) { cout << state({i, j}).online; }
      cout << endl;
    }
  }
  pair<Coord, bool> Move(const Coord& c, int dx, int dy) const {
    if (state({c.x + dx, c.y + dy}).online) {
      return {{0, 0}, false};
    }
    return {{c.x + dx * 2, c.y + dy * 2}, true};
  };
  bool IsEdge(const Coord& c) const {
    return c.x == 1 || (c.x + 1) == (grid_.size() - 1) || c.y == 1 ||
           (c.y + 1) == (grid_[0].size() - 1);
  };
  bool Visited(const Coord& c) const { return state(c).visited; }
  void Visit(const Coord& c) { state({c.x, c.y}).visited = true; }
  const State& state(const Coord& c) const { return grid_[c.x][c.y]; }
  State& state(const Coord& c) { return grid_[c.x][c.y]; }

 private:
  vector<vector<State>> grid_;
};

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
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
  xs.insert(*xs.begin() - 1);
  xs.insert(*xs.rbegin() + 1);
  ys.insert(0);
  ys.insert(*ys.begin() - 1);
  ys.insert(*ys.rbegin() + 1);

  vector<int> cx = Compress(vector<int>(xs.begin(), xs.end()));
  vector<int> cy = Compress(vector<int>(ys.begin(), ys.end()));

  Grid grid(cx.size(), cy.size());

  REP(i, N) grid.DrawLineX(Index(cx, A[i]), Index(cx, B[i]), Index(cy, C[i]));
  REP(i, M) grid.DrawLineY(Index(cx, D[i]), Index(cy, E[i]), Index(cy, F[i]));

  Coord init = grid.At(Index(cx, 0), Index(cy, 0));

  queue<Coord> que;
  que.push(init);

  grid.Visit(init);

  long long ans = 0;
  while (!que.empty()) {
    Coord here = que.front();
    que.pop();

    if (grid.IsEdge(here)) {
      ans = -1;
      break;
    }
    long long x = cx[here.x / 2 + 1] - cx[here.x / 2];
    long long y = cy[here.y / 2 + 1] - cy[here.y / 2];
    ans += x * y;
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
