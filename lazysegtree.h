#include <atcoder/lazysegtree>

namespace update_min {
using S = int64_t;
using F = int64_t;
S e() { return std::numeric_limits<S>::max(); }
F id() { return std::numeric_limits<F>::max(); }
S op(S a, S b) { return std::min(a, b); }
S mapping(F f, S x) { return (f == id() ? x : f); }
F composition(F f, F g) { return (f == id() ? g : f); }
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
using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
}  // namespace add_sum
