#include <cassert>
#include <ostream>
#include <set>
#include <vector>

// Interval represents [left, right) with value.
struct Interval {
  int left, right, value;
  bool Contains(int x) const { return left <= x && x < right; }
  bool operator<(const Interval& i) const { return left < i.left; };
};

std::ostream& operator<<(std::ostream& os, const Interval& i) {
  os << "[" << i.left << "," << i.right << ")";
  if (i.value != 0) os << "=" << i.value;
  return os;
}

class Intervals : public std::set<Interval> {
 public:
  void Insert(int left, int right, int value = 0) {
    auto it = LowerBound(left);
    if (it != begin()) {
      auto pit = prev(it);
      if (pit->right == left && pit->value == value) {
        left = pit->left;
        erase(pit);
      }
    }
    if (it != end()) {
      if (right == it->left && value == it->value) {
        right = it->right;
        erase(it);
      }
    }
    insert({left, right, value});
  }
  std::vector<Interval> Erase(int left, int right) {
    auto it = LowerBound(left), jt = it;
    while (jt != end() && jt->left < right) ++jt;
    std::vector<Interval> erased(it, jt);
    erase(it, jt);
    if (!erased.empty()) {
      if (auto& i = erased[0]; i.left < left) {
        insert({i.left, left, i.value});
        i.left = left;
      }
      if (auto& i = erased.back(); right < i.right) {
        insert({right, i.right, i.value});
        i.right = right;
      }
    }
    return erased;
  }
  std::set<Interval>::iterator LowerBound(int x) const {
    auto it = lower_bound({x, 0, 0});
    if (it != begin() && x < prev(it)->right) --it;
    return it;
  }
  std::optional<Interval> Find(int x) const {
    auto it = LowerBound(x);
    if (it != end() && it->Contains(x)) return *it;
    return std::nullopt;
  }
  int Mex(int left) const {
    auto i = Find(left);
    return i ? i->right : left;
  }
};
