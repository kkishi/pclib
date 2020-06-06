#include <functional>

template <typename T>
T BinarySearch(T lo, T hi, std::function<bool(T)> pred) {
  while (lo + 1 < hi) {
    T mid = (lo + hi) / 2;
    if (pred(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return lo;
}
