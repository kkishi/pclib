#include "compress.h"

#include "gtest/gtest.h"

TEST(compress, simple) {
  std::vector<int> v = {-1, 2, 7, 2, 5};
  std::vector<int> c = Compress(v);
  EXPECT_EQ(c, std::vector<int>({-1, 2, 5, 7}));
  EXPECT_EQ(Index(c, 5), 2);
}
