#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

std::vector<int64_t> SuffixArray(const std::string& s) {
  int n = s.size();
  std::vector<int64_t> r(n), nr(n), v(n);
  for (int i = 0; i < n; ++i) {
    r[i] = s[i];
    v[i] = i;
  }
  for (int l = 1; l < n; l *= 2) {
    auto lt = [&](int i, int j) {
      if (r[i] != r[j]) return r[i] < r[j];
      int ri = i + l < n ? r[i + l] : -1;
      int rj = j + l < n ? r[j + l] : -1;
      return ri < rj;
    };
    std::sort(v.begin(), v.end(), lt);
    nr[v[0]] = 0;
    for (int i = 1; i < n; ++i) {
      nr[v[i]] = nr[v[i - 1]] + lt(v[i - 1], v[i]);
    }
    swap(r, nr);
  }
  return v;
}
