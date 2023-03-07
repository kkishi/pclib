#include <cstdint>
#include <map>

#include "binary_search.h"
#include "dassert.h"

class ConvexHullTrick {
  using i64 = int64_t;

 public:
  void Add(i64 a, i64 b) {
    auto [it, ok] = mp_.insert({a, b});
    if (!ok && it->second >= b) return;
    auto necessary = [&](auto it) -> bool {
      if (it == mp_.begin()) return true;
      auto [al, bl] = *prev(it);

      auto jt = next(it);
      if (jt == mp_.end()) return true;
      auto [ar, br] = *jt;

      auto [am, bm] = *it;
      return (am - al) * (bl - br) > (bl - bm) * (ar - al);
    };
    if (!necessary(it)) {
      mp_.erase(it);
      return;
    }
    for (auto jt = it; jt != mp_.begin();) {
      --jt;
      if (necessary(jt)) break;
      auto kt = prev(jt);
      mp_.erase(jt);
      jt = kt;
    }
    for (auto jt = next(it); jt != mp_.end();) {
      if (necessary(jt)) break;
      auto kt = next(jt);
      mp_.erase(jt);
      jt = kt;
    }
  }
  i64 Get(i64 x) const {
    dassert(!mp_.empty());
    i64 a = BinarySearch<i64>(
        mp_.begin()->first, prev(mp_.end())->first + 1, [&](i64 a) -> bool {
          auto it = mp_.lower_bound(a);
          if (it == mp_.begin()) return true;
          auto jt = prev(it);
          return it->first * x + it->second > jt->first * x + jt->second;
        });
    auto it = mp_.find(a);
    dassert(it != mp_.end() && it->first == a);
    return it->first * x + it->second;
  }

 private:
  std::map<i64, i64> mp_;
};
