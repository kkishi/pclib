#include <map>
#include <vector>

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

template <typename T>
std::vector<T> Divisors(T x) {
  std::vector<T> h, t;
  for (T i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      h.push_back(i);
      if (int j = x / i; j != i) t.push_back(j);
    }
  }
  copy(t.rbegin(), t.rend(), back_inserter(h));
  return h;
}
