#include "rational.h"

#include <sstream>

#include "gtest/gtest.h"

TEST(rational, simple) {
  Rational rat(1, 2);
  EXPECT_EQ(rat.n(), 1);
  EXPECT_EQ(rat.d(), 2);
}

TEST(rational, normalization) {
  Rational rat(2 * 3 * 5, -3 * 5 * 7);
  EXPECT_EQ(rat.n(), -2);
  EXPECT_EQ(rat.d(), 7);
}

TEST(rational, normalization_negative) {
  Rational rat(-3, -7);
  EXPECT_EQ(rat.n(), 3);
  EXPECT_EQ(rat.d(), 7);
}

TEST(rational, zero) {
  Rational rat(0, -42);
  EXPECT_EQ(rat.n(), 0);
  EXPECT_EQ(rat.d(), 1);
}

TEST(rational, stream) {
  std::ostringstream oss;
  Rational rat(-3, 7);
  oss << rat;
  EXPECT_EQ(oss.str(), "-3/7");
}
