#include "gcd.h"

#include "gtest/gtest.h"

TEST(gcd, simple) {
  EXPECT_EQ(Gcd<int>(13, 13), 13);
  EXPECT_EQ(Gcd<int>(37, 600), 1);
  EXPECT_EQ(Gcd<int>(20, 100), 20);
  EXPECT_EQ(Gcd<int>(624129, 2061517), 18913);
}

TEST(extgcd, simple) {
  EXPECT_EQ(ExtGcd<int>(252, 105), std::make_tuple(21, -2, 5));
  EXPECT_EQ(ExtGcd<int>(111, 30), std::make_tuple(3, 3, -11));
  EXPECT_EQ(ExtGcd<int>(624129, 2061517), std::make_tuple(18913, -33, 10));
}
