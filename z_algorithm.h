#include <cstdint>
#include <string>
#include <vector>

// https://www.cs.cmu.edu/~ckingsf/bioinfo-lectures/zalg.pdf
std::vector<int64_t> ZAlgorithm(const std::string& s) {
  int n = s.size();
  std::vector<int64_t> z(n);
  z[0] = n;
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (r <= i) {
      int j = 0;
      while (i + j < n && s[j] == s[i + j]) ++j;
      z[i] = j;
      if (j > 0) {
        l = i, r = i + j;
      }
    } else {
      if (z[i - l] < r - i) {
        z[i] = z[i - l];
      } else {
        int j = 0;
        while (r + j < n && s[z[i - l] + j] == s[r + j]) ++j;
        z[i] = r + j - i;
        l = i, r = r + j;
      }
    }
  }
  return z;
}
