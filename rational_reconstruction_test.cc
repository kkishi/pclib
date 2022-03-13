#include "rational_reconstruction.h"

#include <numeric>

#include "gtest/gtest.h"

using mint = ModInt<998244353>;

TEST(rational_reconstruction, simple) {
  EXPECT_EQ(RationalReconstruction(mint(221832079)),
            (std::pair<i64, i64>{5, 9}));
}

TEST(rational_reconstruction, small) {
  for (int i = 1; i <= 100; ++i) {
    for (int j = 1; j <= 100; ++j) {
      mint x = mint(i) / mint(j);
      int g = std::gcd(i, j);
      std::pair<i64, i64> want = {i / g, j / g};
      EXPECT_EQ(RationalReconstruction(x), want);
    }
  }
}
