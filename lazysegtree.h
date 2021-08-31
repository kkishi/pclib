#include <atcoder/lazysegtree>

// NOTE: This implementation assumes that the value equal id() will never be
// passed to the methods, such as apply. If it happens, it fails to update.
namespace update_min {
using S = int64_t;
using F = int64_t;
S e() { return std::numeric_limits<S>::max(); }
F id() { return std::numeric_limits<F>::max(); }
S op(S a, S b) { return std::min(a, b); }
S mapping(F f, S x) { return f == id() ? x : f; }
F composition(F f, F g) { return f == id() ? g : f; }
using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
}  // namespace update_min

namespace add_min {
using S = int64_t;
using F = int64_t;
S e() { return std::numeric_limits<S>::max(); }
F id() { return 0; }
S op(S a, S b) { return std::min(a, b); }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
}  // namespace add_min

// NOTE: This implementation assumes that the value equal id() will never be
// passed to the methods, such as apply. If it happens, it fails to update.
namespace update_sum {
struct S {
  int64_t val;
  int64_t len;
};
using F = int64_t;
S e() { return {0, 0}; }
F id() { return std::numeric_limits<int>::max(); }
S op(S a, S b) { return {a.val + b.val, a.len + b.len}; }
S mapping(F f, S x) {
  if (f != id()) x.val = f * x.len;
  return x;
}
F composition(F f, F g) { return f == id() ? g : f; }
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
using F = int64_t;
S e() { return {0, 0}; }
F id() { return 0; }
S op(S a, S b) { return {a.val + b.val, a.len + b.len}; }
S mapping(F f, S x) { return {x.val + f * x.len, x.len}; }
F composition(F f, F g) { return f + g; }
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
