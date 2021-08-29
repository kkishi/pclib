#include <cassert>
#include <ostream>
#include <set>
#include <vector>

// Interval represents [left, right) with value.
struct Interval {
  int64_t left, right, value;
  bool Contains(int64_t x) const { return left <= x && x < right; }
  bool operator<(const Interval& i) const { return left < i.left; };
};

std::ostream& operator<<(std::ostream& os, const Interval& i) {
  os << "[" << i.left << "," << i.right << ")";
  if (i.value != 0) os << "=" << i.value;
  return os;
}

class Intervals : public std::set<Interval> {
 public:
  // Inserts an interval [left, right) with vlaue. If it would result in
  // consecutive intervals with the same value, they are concatenated.
  //
  // NOTE: The new interval must not overlap with any existing intervals. Call
  // Erase first to ensure that if necessary.
  void Insert(int64_t left, int64_t right, int64_t value = 0) {
    auto it = LowerBound(left);
    if (it != begin()) {
      auto pit = prev(it);
      assert(pit->right <= left);  // Assert no overlap on the left.
      if (pit->right == left && pit->value == value) {
        left = pit->left;
        erase(pit);
      }
    }
    if (it != end()) {
      assert(right <= it->left);  // Assert no overlap on the right.
      if (right == it->left && value == it->value) {
        right = it->right;
        erase(prev(++it));  // Adjust it so that it can later be used as a hint.
      }
    }
    insert(it, {left, right, value});
  }

  // Erases intervals that overlap with [left, right). Partial overlaps are
  // erased partially. Returns erased intervals.
  std::vector<Interval> Erase(int64_t left, int64_t right) {
    auto it = LowerBound(left), jt = it;
    while (jt != end() && jt->left < right) ++jt;
    std::vector<Interval> erased(it, jt);
    erase(it, jt);
    if (!erased.empty()) {
      if (auto& i = erased[0]; i.left < left) {
        insert(jt, {i.left, left, i.value});
        i.left = left;
      }
      if (auto& i = erased.back(); right < i.right) {
        insert(jt, {right, i.right, i.value});
        i.right = right;
      }
    }
    return erased;
  }

  // Returns the first interval that either contains x or is on the right of x.
  std::set<Interval>::iterator LowerBound(int64_t x) const {
    auto it = lower_bound({x, 0, 0});
    if (it != begin() && x < prev(it)->right) --it;
    return it;
  }

  // Returns an interval containing x if exists.
  std::optional<Interval> Find(int64_t x) const {
    auto it = LowerBound(x);
    if (it != end() && it->Contains(x)) return *it;
    return std::nullopt;
  }

  // Returns mex[left, infinity).
  int64_t Mex(int64_t left) const {
    auto i = Find(left);
    return i ? i->right : left;
  }
};
