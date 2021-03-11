#include "extgcd.h"
#include "gtest/gtest.h"

TEST(extgcd, simple) {
  EXPECT_EQ(ExtGcd<int>(252, 105), std::make_tuple(21, -2, 5));
  EXPECT_EQ(ExtGcd<int>(111, 30), std::make_tuple(3, 3, -11));
  EXPECT_EQ(ExtGcd<int>(624129, 2061517), std::make_tuple(18913, -33, 10));
}
