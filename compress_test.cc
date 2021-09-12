#include "compress.h"

#include "gtest/gtest.h"

TEST(compress, simple) {
  std::vector<int64_t> v = {-1, 2, 7, 2, 5};
  std::vector<int64_t> w = {-1, 2, 5, 7};
  Compressor c(v);
  for (int i = 0; i < w.size(); ++i) {
    EXPECT_EQ(c(w[i]), i);
    EXPECT_EQ(c[i], w[i]);
  }
}
