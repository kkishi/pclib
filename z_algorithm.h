#include <cstdint>
#include <string>
#include <vector>

// https://www.cs.cmu.edu/~ckingsf/bioinfo-lectures/zalg.pdf
std::vector<int64_t> ZAlgorithm(const std::string& s) {
  int n = s.size();
  std::vector<int64_t> z(n);
  z[0] = n;
  int l = 0, r = 0;
  for (int k = 1; k < n; ++k) {
    if (r <= k) {
      l = r = k;
      while (r < n && s[r - l] == s[r]) ++r;
      z[k] = r - l;
      continue;
    }
    if (z[k - l] < r - k) {
      z[k] = z[k - l];
      continue;
    }
    l = k;
    while (r < n && s[r - l] == s[r]) ++r;
    z[k] = r - l;
  }
  return z;
}

std::vector<int> ZMatch(const std::string& t, const std::string& p) {
  auto z = ZAlgorithm(p + '$' + t);
  int n = t.size(), m = p.size();
  std::vector<int> ret;
  for (int i = 0; i < n; ++i) {
    if (z[m + 1 + i] == m) {
      ret.push_back(i);
    }
  }
  return ret;
}
