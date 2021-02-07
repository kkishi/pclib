#include <vector>

std::vector<bool> Sieve(int n) {
  std::vector<bool> v(n + 1, true);
  v[0] = v[1] = false;
  for (int i = 2; i * i <= n; ++i) {
    if (!v[i]) {
      continue;
    }
    for (int j = i * 2; j <= n; j += i) {
      v[j] = false;
    }
  }
  return v;
}

std::vector<int> Primes(int n) {
  std::vector<bool> sieve = Sieve(n);
  std::vector<int> v;
  for (int i = 2; i <= n; ++i) {
    if (sieve[i]) {
      v.push_back(i);
    }
  }
  return v;
}
