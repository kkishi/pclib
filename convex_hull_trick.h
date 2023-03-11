#include <cstdint>
#include <map>
#include <queue>

#include "binary_search.h"
#include "dassert.h"

class MaxConvexHullTrick {
 public:
  // O(log n)
  void Add(int64_t a, int64_t b) {
    auto [it, ok] = mp_.insert({a, b});
    if (!ok && b <= it->second) return;
    auto erase = [&](auto it) -> bool {
      if (it == mp_.begin()) return false;
      auto [al, bl] = *prev(it);

      auto jt = next(it);
      if (jt == mp_.end()) return false;
      auto [ar, br] = *jt;

      auto [am, bm] = *it;
      if ((bl - bm) * (ar - al) < (am - al) * (bl - br)) return false;
      mp_.erase(it);
      return true;
    };
    if (erase(it)) return;
    while (it != mp_.begin() && erase(prev(it)))
      ;
    while (next(it) != mp_.end() && erase(next(it)))
      ;
  }
  // O((log n)^2)
  int64_t Get(int64_t x) const {
    dassert(!mp_.empty());
    int64_t a = BinarySearch<int64_t>(
        mp_.begin()->first, prev(mp_.end())->first + 1, [&](int64_t a) -> bool {
          auto it = mp_.lower_bound(a);
          if (it == mp_.begin()) return true;
          auto jt = prev(it);
          return jt->first * x + jt->second < it->first * x + it->second;
        });
    auto it = mp_.find(a);
    dassert(it != mp_.end() && it->first == a);
    return it->first * x + it->second;
  }

 private:
  std::map<int64_t, int64_t> mp_;
};

class MinConvexHullTrick {
 public:
  void Add(int64_t a, int64_t b) { cht_.Add(-a, -b); }
  int64_t Get(int64_t x) const { return -cht_.Get(x); }

 private:
  MaxConvexHullTrick cht_;
};

class MaxMonotoneConvexHullTrick {
 public:
  // O(1)
  void Add(int64_t a, int64_t b) {
    if (!que_.empty()) dassert(que_.back().first < a);
    while (que_.size() >= 2) {
      auto [al, bl] = que_[que_.size() - 2];
      auto [am, bm] = que_[que_.size() - 1];
      if ((bl - bm) * (a - al) < (am - al) * (bl - b)) break;
      que_.pop_back();
    }
    que_.emplace_back(a, b);
  }
  // O(log n)
  int64_t Get(int64_t x) const {
    dassert(!que_.empty());
    int32_t i = BinarySearch<int32_t>(0, que_.size(), [&](int32_t i) -> bool {
      if (i == 0) return true;
      auto [ai, bi] = que_[i];
      auto [aj, bj] = que_[i - 1];
      return aj * x + bj < ai * x + bi;
    });
    auto [a, b] = que_[i];
    return a * x + b;
  }

 private:
  std::deque<std::pair<int64_t, int64_t>> que_;
};
class MinMonotoneConvexHullTrick {
 public:
  void Add(int64_t a, int64_t b) { cht_.Add(-a, -b); }
  int64_t Get(int64_t x) const { return -cht_.Get(x); }

 private:
  MaxMonotoneConvexHullTrick cht_;
};
