#include <cstdint>
#include <string>
#include <vector>

std::vector<int> RollingHashMatches(const std::string& haystack,
                                    const std::string& needle) {
  if (haystack.size() < needle.size()) {
    return {};
  }
  const uint64_t base = 100000007;
  uint64_t h = 0, n = 0, t = 1;
  for (std::size_t i = 0; i < needle.size(); ++i) {
    h = h * base + haystack[i];
    n = n * base + needle[i];
    t *= base;
  }
  std::vector<int> matches;
  for (std::size_t i = 0;; ++i) {
    if (h == n) matches.push_back(i);
    std::size_t j = i + needle.size();
    if (j == haystack.size()) break;
    h = h * base - t * haystack[i] + haystack[j];
  }
  return matches;
}
