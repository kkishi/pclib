#include <cstdint>
#include <vector>

template <typename T>
int64_t CountLT(const std::vector<T>& v, T x) {
  return std::lower_bound(v.begin(), v.end(), x) - v.begin();
}

template <typename T>
int64_t CountLE(const std::vector<T>& v, T x) {
  return CountLT(v, x + 1);
}

template <typename T>
int64_t CountGE(const std::vector<T>& v, T x) {
  return v.end() - std::lower_bound(v.begin(), v.end(), x);
}

template <typename T>
int64_t CountGT(const std::vector<T>& v, T x) {
  return CountGE(v, x + 1);
}
