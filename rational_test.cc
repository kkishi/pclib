#include <sstream>

#include "gtest/gtest.h"

#include "rational.h"

TEST(rational, simple) {
  Rational<int> rat(1, 2);
  EXPECT_EQ(rat.numerator(), 1);
  EXPECT_EQ(rat.denominator(), 2);
}

TEST(rational, normalization) {
  Rational<int> rat(2 * 3 * 5, - 3 * 5 * 7);
  EXPECT_EQ(rat.numerator(), -2);
  EXPECT_EQ(rat.denominator(), 7);
}

TEST(rational, normalization_negative) {
  Rational<int> rat(-3, -7);
  EXPECT_EQ(rat.numerator(), 3);
  EXPECT_EQ(rat.denominator(), 7);
}

TEST(rational, zero) {
  Rational<int> rat(0, -42);
  EXPECT_EQ(rat.numerator(), 0);
  EXPECT_EQ(rat.denominator(), 1);
}

TEST(rational, stream) {
  std::ostringstream oss;
  Rational<int> rat(-3, 7);
  oss << rat;
  EXPECT_EQ(oss.str(), "-3/7");
}
