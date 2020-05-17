#include "gtest/gtest.h"

#include "gcd.h"

TEST(gcd, simple) {
  EXPECT_EQ(Gcd<int>(13, 13), 13);
  EXPECT_EQ(Gcd<int>(37, 600), 1);
  EXPECT_EQ(Gcd<int>(20, 100), 20);
  EXPECT_EQ(Gcd<int>(624129, 2061517), 18913);
}
