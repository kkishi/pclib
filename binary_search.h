#ifndef BINARY_SEARCH_H_
#define BINARY_SEARCH_H_

#include <functional>

template <typename T>
T BinarySearch(T ok, T ng, std::function<bool(T)> pred) {
  if constexpr (std::is_floating_point<T>::value) {
    for (int i = 0; i < 200; ++i) {
      T mid = (ok + ng) / 2;
      (pred(mid) ? ok : ng) = mid;
    }
  } else {
    while ((ok > ng ? ok - ng : ng - ok) > 1) {
      T mid = ok + (ng - ok) / 2;
      (pred(mid) ? ok : ng) = mid;
    }
  }
  return ok;
}

#endif
