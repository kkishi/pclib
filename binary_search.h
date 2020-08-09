#include <functional>

template <typename T>
T BinarySearch(T ok, T ng, std::function<bool(T)> pred) {
  while (abs(ok - ng) > 1) {
    T mid = (ok + ng) / 2;
    (pred(mid) ? ok : ng) = mid;
  }
  return ok;
}
