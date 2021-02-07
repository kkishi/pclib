#include <map>
#include <vector>

template <typename T>
std::map<T, int> Factorize(T x) {
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

template <typename T>
std::vector<T> Divisors(T x) {
  std::vector<T> v;
  for (T i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      v.push_back(i);
      v.push_back(x / i);
    }
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  return v;
}
