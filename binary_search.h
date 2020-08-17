#include <functional>

template <typename T>
T BinarySearch(T ok, T ng, std::function<bool(T)> pred) {
  static_assert(std::is_integral<T>::value);
  while ((ok > ng ? ok - ng : ng - ok) > 1) {
    T mid = ok + (ng - ok) / 2;
    (pred(mid) ? ok : ng) = mid;
  }
  return ok;
}
