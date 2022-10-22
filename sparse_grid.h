#include <map>
#include <set>

template <typename T>
T GreaterThanOr(const std::set<T>& s, T val, T def) {
  auto it = s.upper_bound(val);
  if (it == s.end()) return def;
  return *it;
}

template <typename T>
T LessThanOr(const std::set<T>& s, T val, T def) {
  auto it = s.lower_bound(val);
  if (it == s.begin()) return def;
  return *prev(it);
}

class SparseGrid {
 public:
  SparseGrid(int64_t h, int64_t w) : h_(h), w_(w) {}
  void Insert(int64_t r, int64_t c) {
    rs_[c].insert(r);
    cs_[r].insert(c);
  }
  int64_t Left(int64_t r, int64_t c) const {
    return LessThanOr(Find(cs_, r), c, int64_t(-1));
  }
  int64_t Right(int64_t r, int64_t c) const {
    return GreaterThanOr(Find(cs_, r), c, w_);
  }
  int64_t Up(int64_t r, int64_t c) const {
    return LessThanOr(Find(rs_, c), r, int64_t(-1));
  }
  int64_t Down(int64_t r, int64_t c) const {
    return GreaterThanOr(Find(rs_, c), r, h_);
  }

 private:
  const std::set<int64_t>& Find(const std::map<int64_t, std::set<int64_t>>& m,
                                int64_t x) const {
    auto it = m.find(x);
    if (it != m.end()) return it->second;
    static const std::set<int64_t> s;
    return s;
  }

  const int64_t h_, w_;
  std::map<int64_t, std::set<int64_t>> rs_, cs_;
};
