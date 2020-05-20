#include <algorithm>
#include <vector>

template <typename T>
std::vector<T> Compress(std::vector<T> v) {
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  return v;
}

template <typename T>
T Index(const std::vector<T>& v, T x) {
  return std::lower_bound(v.begin(), v.end(), x) - v.begin();
}
