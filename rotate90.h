template <typename T>
T Rotate90(const T& t) {
  int n = t.size(), m = t[0].size();
  T u(m);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      u[i].push_back(t[j][m - 1 - i]);
    }
  }
  return u;
}
