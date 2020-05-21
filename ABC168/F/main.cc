#include <bits/stdc++.h>

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

struct Coord {
  int x, y;
};

ostream& operator<<(ostream& os, const Coord& c) {
  cout << "{" << c.x << "," << c.y << "}";
  return os;
}

template<typename State>
class Grid {
 public:
  Grid(int x, int y) : grid_(x * 2 + 1, vector(y * 2 + 1, State())) {}
  bool InBounds(const Coord& c) const {
    int x = coord(c.x), y = coord(c.y);
    return 0 <= x && x < grid_.size() && 0 <= y && y < grid_[0].size();
  }
  State& StateOf(const Coord& c) {
    return grid_[coord(c.x)][coord(c.y)];
  }
  State& Boundary(const Coord& c, int dx, int dy) {
    return grid_[coord(c.x) + dx][coord(c.y) + dy];
  }
  void Debug(char to_char(const State& s, optional<char> boundary)) const {
    auto is_boundary = [](int x)->bool { return x % 2 == 0; };

    // Print horizontal legend.
    cout << "  ";  // Padding for the vertical legend.
    REP(y, grid_[0].size()) {
      if (is_boundary(y)) {
        cout << " ";
      } else {
        cout << (y / 2) % 10;
      }
    }
    cout << endl;

    REP(x, grid_.size()) {
      // Print vertical legend.
      if (is_boundary(x)) {
        cout << "  ";
      } else {
        cout << (x / 2) % 10 << " ";
      }

      REP(y, grid_[x].size()) {
        if (is_boundary(x) && is_boundary(y)) {
          cout << "+";
          continue;
        }
        optional<char> boundary;
        if (is_boundary(x)) {
          boundary = '-';
        } else if (is_boundary(y)) {
          boundary = '|';
        }
        cout << to_char(grid_[x][y], boundary);
      }
      cout << endl;
    }
  }

 private:
  static int coord(int i) { return i * 2 + 1; }

  vector<vector<State>> grid_;
};

struct GridState {
  bool online;
  bool visited;
};

void DrawLineX(Grid<GridState>& g, int x1, int x2, int y) {
  if (x1 > x2) swap(x1, x2);
  for (int x = x1; x < x2; ++x) {
    g.Boundary({x, y}, 0, -1).online = true;
  }
}

void DrawLineY(Grid<GridState>& g, int x, int y1, int y2) {
  if (y1 > y2) swap(y1, y2);
  for (int y = y1; y < y2; ++y) {
    g.Boundary({x, y}, -1, 0).online = true;
  }
}

void Debug(const Grid<GridState>& g) {
  g.Debug([](const GridState& s, optional<char> boundary)->char {
               if (boundary) {
                 return s.online ? *boundary : ' ';
               }
               return s.visited ? 'o' : ' ';
             });
}

int main() {
  int N, M;
  cin >> N >> M;

  REP(i, N) cin >> A[i] >> B[i] >> C[i];
  REP(i, M) cin >> D[i] >> E[i] >> F[i];

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

  vector cx = Compress(vector(ALL(xs)));
  vector cy = Compress(vector(ALL(ys)));

  Grid<GridState> grid(cx.size() - 1, cy.size() - 1);

  REP(i, N) DrawLineX(grid, Index(cx, A[i]), Index(cx, B[i]), Index(cy, C[i]));
  REP(i, M) DrawLineY(grid, Index(cx, D[i]), Index(cy, E[i]), Index(cy, F[i]));

  Coord init = {Index(cx, 0), Index(cy, 0)};

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
    REP(i, 4) {
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
  cout << ans << endl;
}
