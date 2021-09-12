#include "compressor.h"

#include "gtest/gtest.h"

TEST(compressor, simple) {
  std::vector<int64_t> v = {-1, 2, 7, 2, 5};
  std::vector<int64_t> w = {-1, 2, 5, 7};
  Compressor c(v);
  EXPECT_EQ(c.coord, w);
  for (size_t i = 0; i < w.size(); ++i) {
    EXPECT_EQ(c(w[i]), i);
  }
}
