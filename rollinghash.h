#include <string>
#include <vector>

std::vector<int> Matches(const std::string& haystack,
                         const std::string& needle) {
  const long long base = 100000007;
  if (haystack.size() < needle.size()) {
    return {};
  }
  long long h = 0, n = 0, t = 1;
  for (int i = 0; i < needle.size(); ++i) {
    h = h * base + haystack[i];
    n = n * base + needle[i];
    t *= base;
  }
  std::vector<int> matches;
  for (int i = 0;; ++i) {
    if (h == n) matches.push_back(i);
    int j = i + needle.size();
    if (j == haystack.size()) break;
    h = h * base - t * haystack[i] + haystack[j];
  }
  return matches;
}
