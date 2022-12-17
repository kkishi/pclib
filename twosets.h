#include <cstdint>
#include <set>

#include "dassert.h"

class SetWithSum {
  using i64 = int64_t;

 public:
  void Add(i64 x) {
    set_.insert(x);
    sum_ += x;
  }
  bool Rem(i64 x) {
    auto it = set_.find(x);
    if (it == set_.end()) return false;
    sum_ -= x;
    set_.erase(it);
    return true;
  }
  const std::multiset<i64>& set() const { return set_; }
  i64 sum() const { return sum_; }

  std::multiset<i64> set_;
  i64 sum_ = 0;
};

class TwoSets {
  using i64 = int64_t;

 public:
  void Add(i64 x) {
    if (h_.set().empty() || x < *h_.set().begin()) {
      l_.Add(x);
    } else {
      h_.Add(x);
    }
  }
  void Rem(i64 x) { l_.Rem(x) || h_.Rem(x); }
  i64 Size() const { return l_.set().size() + h_.set().size(); }
  void Adjust(i64 k) {
    dassert(k <= Size());
    while (i64(l_.set().size()) < k) {
      int x = *h_.set().begin();
      l_.Add(x);
      h_.Rem(x);
    }
    while (i64(l_.set().size()) > k) {
      int x = *prev(l_.set().end());
      h_.Add(x);
      l_.Rem(x);
    }
  }
  i64 Sum() const { return LSum() + HSum(); }
  i64 LSum() const { return l_.sum(); }
  i64 HSum() const { return h_.sum(); }

 private:
  SetWithSum l_, h_;
};
