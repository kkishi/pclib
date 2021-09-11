template <typename T>
T Rotate90(const T& t) {
  int n = t.size(), m = t[0].size();
  T u(m);
  for (int i = 0; i < m; ++i) {
    u[i].resize(n);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      u[j][n - 1 - i] = t[i][j];
    }
  }
  return u;
}
