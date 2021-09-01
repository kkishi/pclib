#include "primitive_root.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::ElementsAre;

TEST(primitive_root, simple) {
  int64_t p = 13;
  std::vector<int> r;
  for (int64_t i = 1; i < p; ++i) {
    if (IsPrimitiveRoot(i, p)) r.push_back(i);
  }
  EXPECT_THAT(r, ElementsAre(2, 6, 7, 11));
}

TEST(primitive_root, large) {
  int64_t p = (1LL << 61) - 1;
  EXPECT_FALSE(IsPrimitiveRoot(3, p));
  EXPECT_TRUE(IsPrimitiveRoot(37, p));
}
