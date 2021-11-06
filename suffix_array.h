#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

#include "binary_search.h"

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

std::pair<int64_t, int64_t> SuffixArraySearch(const std::string& s,
                                              const std::vector<int64_t>& sa,
                                              const std::string& p) {
  int n = s.size();
  int64_t l = 0, r = n;
  for (size_t i = 0; i < p.size(); ++i) {
    l = BinarySearch<int64_t>(l, r + 1, [&](int x) {
      if (x == l) return true;
      int y = sa[x - 1] + i;
      if (y >= n) return true;
      return s[y] < p[i];
    });
    r = BinarySearch<int64_t>(l, r + 1, [&](int x) {
      if (x == l) return true;
      int y = sa[x - 1] + i;
      if (y >= n) return true;
      return s[y] <= p[i];
    });
  }
  return {l, r};
}
