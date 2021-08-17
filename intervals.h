#include <cassert>
#include <set>
#include <vector>

class Intervals {
 public:
  struct Interval {
    int begin, end, value;
    bool operator<(const Interval& i) const { return begin < i.begin; };
  };
  void Insert(int begin, int end, int value) {
    auto it = s_.lower_bound({begin, 0, 0});
    if (it != s_.begin()) {
      auto pit = prev(it);
      assert(pit->end <= begin);
      if (pit->end == begin && pit->value == value) {
        begin = pit->begin;
        s_.erase(pit);
      }
    }
    if (it != s_.end()) {
      assert(end <= it->begin);
      if (end == it->begin && value == it->value) {
        end = it->end;
        s_.erase(it);
      }
    }
    s_.insert({begin, end, value});
  }
  std::vector<Interval> Erase(int begin, int end) {
    auto it = s_.lower_bound({begin, 0, 0});
    if (it != s_.begin() && begin < prev(it)->end) --it;
    auto jt = it;
    while (jt != s_.end() && jt->begin < end) ++jt;
    std::vector<Interval> erased(it, jt);
    s_.erase(it, jt);
    if (!erased.empty()) {
      if (auto& i = erased[0]; i.begin < begin) {
        s_.insert({i.begin, begin, i.value});
        i.begin = begin;
      }
      if (auto& i = erased.back(); end < i.end) {
        s_.insert({end, i.end, i.value});
        i.end = end;
      }
    }
    return erased;
  }

 private:
  std::set<Interval> s_;
};
