#include <cstdint>
#include <unordered_set>

#include "int_sqrt.h"

// Based on the algorithm:
// https://maspypy.com/%e3%83%a2%e3%83%8e%e3%82%a4%e3%83%89%e4%bd%9c%e7%94%a8%e3%81%ab%e9%96%a2%e3%81%99%e3%82%8b%e9%9b%a2%e6%95%a3%e5%af%be%e6%95%b0%e5%95%8f%e9%a1%8c
template <typename X, typename S>
int64_t BSGS(X x, S s, S t, int64_t n, std::function<X(X, X)> xx,
             std::function<S(X, S)> xs) {
  int64_t m = IntSqrt(n);
  std::unordered_set<S> st;
  S xt = t;
  for (int64_t i = 0; i < m; ++i) {
    xt = xs(x, xt);
    st.insert(xt);
  }
  X xm = x;
  for (int64_t i = 0; i < m - 1; ++i) {
    xm = xx(x, xm);
  }
  S xkms = s;
  int found = 0;
  for (int64_t i = 0; i * m < n && found < 2; ++i) {
    S next = xs(xm, xkms);
    if (st.count(next)) {
      ++found;
      S xns = xkms;
      for (int64_t j = 0; j < m; ++j) {
        if (xns == t) {
          return i * m + j;
        }
        xns = xs(x, xns);
      }
    }
    xkms = next;
  }
  return -1;
}
