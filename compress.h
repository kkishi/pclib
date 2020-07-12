#include <algorithm>
#include <functional>
#include <vector>

template <typename T>
std::vector<T> Compress(std::vector<T> v) {
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  return v;
}

template <typename T>
T Uncompress(const std::vector<T>& v, T x) {
  return std::lower_bound(v.begin(), v.end(), x) - v.begin();
}

template <typename T>
std::function<T(T)> Uncompressor(const std::vector<T>& v) {
  return [&v](T i) -> T { return Uncompress(v, i); };
}
