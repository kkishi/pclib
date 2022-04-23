#include <cstdint>
#include <set>

#include "dassert.h"

class TwoSets {
  using i64 = int64_t;

 public:
  void Add(i64 x) {
    l_.insert(x);
    ls_ += x;
  }
  i64 Size() const { return l_.size() + h_.size(); }
  void Adjust(i64 k) {
    dassert(k <= Size());
    while (i64(l_.size()) < k) {
      auto it = h_.begin();
      l_.insert(*it);
      ls_ += *it;
      hs_ -= *it;
      h_.erase(it);
    }
    while (i64(l_.size()) > k) {
      auto it = prev(l_.end());
      h_.insert(*it);
      hs_ += *it;
      ls_ -= *it;
      l_.erase(it);
    }
  }
  i64 Sum() const { return ls_ + hs_; }
  i64 LSum() const { return ls_; }
  i64 HSum() const { return hs_; }

 private:
  std::multiset<i64> l_, h_;
  i64 ls_ = 0, hs_ = 0;
};
