#include <map>

template <typename T>
std::map<T, int> Factors(T x) {
  std::map<T, int> m;
  for (T i = 2; i * i <= x;) {
    if (x % i == 0) {
      m[i]++;
      x /= i;
    } else {
      ++i;
    }
  }
  if (x > 1) m[x]++;
  return m;
}
