#include <cstdint>
#include <map>

#include "binary_search.h"
#include "dassert.h"

template <typename T, typename Cmp>
class ConvexHullTrick {
 public:
  void Add(T a, T b) {
    auto [it, ok] = mp_.insert({a, b});
    if (!ok && cmp_(b, it->second)) return;
    auto erase = [&](auto it) -> bool {
      if (it == mp_.begin()) return false;
      auto [al, bl] = *prev(it);

      auto jt = next(it);
      if (jt == mp_.end()) return false;
      auto [ar, br] = *jt;

      auto [am, bm] = *it;
      if (cmp_((bl - bm) * (ar - al), (am - al) * (bl - br))) return false;
      mp_.erase(it);
      return true;
    };
    if (erase(it)) return;
    for (auto jt = it; jt != mp_.begin();) {
      --jt;
      auto kt = prev(jt);
      if (!erase(jt)) break;
      jt = kt;
    }
    for (auto jt = next(it); jt != mp_.end();) {
      auto kt = next(jt);
      if (!erase(jt)) break;
      jt = kt;
    }
  }
  T Get(T x) const {
    dassert(!mp_.empty());
    T a = BinarySearch<T>(
        mp_.begin()->first, prev(mp_.end())->first + 1, [&](T a) -> bool {
          auto it = mp_.lower_bound(a);
          if (it == mp_.begin()) return true;
          auto jt = prev(it);
          return cmp_(jt->first * x + jt->second, it->first * x + it->second);
        });
    auto it = mp_.find(a);
    dassert(it != mp_.end() && it->first == a);
    return it->first * x + it->second;
  }

 private:
  std::map<T, T> mp_;
  static const Cmp cmp_;
};

using MaxConvexHullTrick = ConvexHullTrick<int64_t, std::less<int64_t>>;
using MinConvexHullTrick = ConvexHullTrick<int64_t, std::greater<int64_t>>;
