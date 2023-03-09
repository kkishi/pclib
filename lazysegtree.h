#include <atcoder/lazysegtree>
#include <optional>

namespace update_min {
using S = int64_t;
S op(S a, S b) { return std::min(a, b); }
S e() { return std::numeric_limits<S>::max(); }
using F = std::optional<int64_t>;
S mapping(F f, S x) { return f ? *f : x; }
F composition(F f, F g) { return f ? f : g; }
F id() { return std::nullopt; }
using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
}  // namespace update_min

namespace add_min {
using S = int64_t;
S op(S a, S b) { return std::min(a, b); }
S e() { return std::numeric_limits<S>::max(); }
using F = int64_t;
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }
using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
}  // namespace add_min

namespace add_max {
using S = int64_t;
S op(S a, S b) { return std::max(a, b); }
S e() { return std::numeric_limits<S>::min(); }
using F = int64_t;
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }
using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
}  // namespace add_max

namespace update_sum {
struct S {
  int64_t val;
  int64_t len;
};
S op(S a, S b) { return {a.val + b.val, a.len + b.len}; }
S e() { return {0, 0}; }
using F = std::optional<int64_t>;
S mapping(F f, S x) {
  if (f) x.val = *f * x.len;
  return x;
}
F composition(F f, F g) { return f ? f : g; }
F id() { return std::nullopt; }
class segtree
    : public atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> {
 public:
  segtree() : lazy_segtree() {}
  explicit segtree(int n) : lazy_segtree(std::vector<S>(n, {0, 1})) {}
  explicit segtree(const std::vector<int64_t>& v) : lazy_segtree(itos(v)) {}

 private:
  static std::vector<S> itos(const std::vector<int64_t>& v) {
    std::vector<S> w(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
      w[i] = {v[i], 1};
    }
    return w;
  }
};
}  // namespace update_sum

namespace add_sum {
struct S {
  int64_t val;
  int64_t len;
};
S op(S a, S b) { return {a.val + b.val, a.len + b.len}; }
S e() { return {0, 0}; }
using F = int64_t;
S mapping(F f, S x) { return {x.val + f * x.len, x.len}; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }
class segtree
    : public atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> {
 public:
  segtree() : lazy_segtree() {}
  explicit segtree(int n) : lazy_segtree(std::vector<S>(n, {0, 1})) {}
  explicit segtree(const std::vector<int64_t>& v) : lazy_segtree(itos(v)) {}

 private:
  static std::vector<S> itos(const std::vector<int64_t>& v) {
    std::vector<S> w(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
      w[i] = {v[i], 1};
    }
    return w;
  }
};
}  // namespace add_sum
