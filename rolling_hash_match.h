#include <cstdint>
#include <string>
#include <vector>

std::vector<int> RollingHashMatches(const std::string& haystack,
                                    const std::string& needle) {
  if (haystack.size() < needle.size()) {
    return {};
  }
  auto roll = [](uint64_t& x, char c) { x = x * 100000007 + c; };
  uint64_t h = 0, n = 0, t = 1;
  for (std::size_t i = 0; i < needle.size(); ++i) {
    roll(h, haystack[i]);
    roll(n, needle[i]);
    roll(t, 0);
  }
  std::vector<int> matches;
  for (std::size_t i = 0;; ++i) {
    if (h == n) matches.push_back(i);
    std::size_t j = i + needle.size();
    if (j == haystack.size()) break;
    roll(h, haystack[j]);
    h -= t * haystack[i];
  }
  return matches;
}
