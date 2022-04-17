#include "rational.h"

#include <sstream>

#include "gtest/gtest.h"

TEST(rational, simple) {
  Rational rat(1, 2);
  rat.Normalize();
  EXPECT_EQ(rat.first, 1);
  EXPECT_EQ(rat.second, 2);
}

TEST(rational, normalization) {
  Rational rat(2 * 3 * 5, -3 * 5 * 7);
  rat.Normalize();
  EXPECT_EQ(rat.first, -2);
  EXPECT_EQ(rat.second, 7);
}

TEST(rational, normalization_negative) {
  Rational rat(-3, -7);
  rat.Normalize();
  EXPECT_EQ(rat.first, 3);
  EXPECT_EQ(rat.second, 7);
}

TEST(rational, zero) {
  Rational rat(0, -42);
  rat.Normalize();
  EXPECT_EQ(rat.first, 0);
  EXPECT_EQ(rat.second, 1);
}

TEST(rational, stream) {
  std::ostringstream oss;
  Rational rat(-3, 7);
  oss << rat;
  EXPECT_EQ(oss.str(), "-3/7");
}
