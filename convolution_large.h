#include <atcoder/convolution>

// https://judge.yosupo.jp/submission/87828
namespace suisen {
template <typename mint, atcoder::internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution_large(const std::vector<mint>& a,
                                    const std::vector<mint>& b) {
  static constexpr int max_size = (mint::mod() - 1) & -(mint::mod() - 1);
  static constexpr int len = max_size >> 1;
  static constexpr int inv_max_size =
      atcoder::internal::inv_gcd(max_size, mint::mod()).second;

  const int n = int(a.size()), m = int(b.size());
  if (n == 0 or m == 0) return {};
  if (n + m - 1 <= max_size) return atcoder::convolution(a, b);

  const int dn = (n + len - 1) / len;
  const int dm = (m + len - 1) / len;

  std::vector<std::vector<mint>> as(dn), bs(dm);
  for (int i = 0; i < dn; ++i) {
    const int offset = len * i;
    as[i] = std::vector<mint>(a.begin() + offset,
                              a.begin() + std::min(n, offset + len));
    as[i].resize(max_size);
    atcoder::internal::butterfly(as[i]);
  }
  for (int j = 0; j < dm; ++j) {
    const int offset = len * j;
    bs[j] = std::vector<mint>(b.begin() + offset,
                              b.begin() + std::min(m, offset + len));
    bs[j].resize(max_size);
    atcoder::internal::butterfly(bs[j]);
  }
  std::vector<std::vector<mint>> cs(dn + dm - 1, std::vector<mint>(max_size));
  for (int i = 0; i < dn; ++i)
    for (int j = 0; j < dm; ++j) {
      for (int k = 0; k < max_size; ++k) cs[i + j][k] += as[i][k] * bs[j][k];
    }
  std::vector<mint> res(n + m - 1);
  for (int i = 0; i < dn + dm - 1; ++i) {
    atcoder::internal::butterfly_inv(cs[i]);
    const int offset = len * i;
    const int jmax = std::min(n + m - 1 - offset, max_size);
    for (int j = 0; j < jmax; ++j) {
      res[offset + j] += cs[i][j] * mint::raw(inv_max_size);
    }
  }
  return res;
}
}  // namespace suisen
