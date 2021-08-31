#include <cstdint>
#include <string>
#include <vector>

// https://www.cs.cmu.edu/~ckingsf/bioinfo-lectures/zalg.pdf
std::vector<int64_t> ZAlgorithm(const std::string& s) {
  int n = s.size();
  std::vector<int64_t> Z(n);
  Z[0] = n;
  int l = 0, r = 0;
  for (int k = 1; k < n; ++k) {
    if (r <= k) {
      l = r = k;
      while (r < n && s[r - l] == s[r]) ++r;
      Z[k] = r - l;
      continue;
    }
    int Zkd = Z[k - l];
    if (Zkd < r - k) {
      Z[k] = Zkd;
      continue;
    }
    l = k;
    while (r < n && s[Zkd] == s[r]) ++Zkd, ++r;
    Z[k] = r - l;
  }
  return Z;
}
