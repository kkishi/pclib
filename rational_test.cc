#include "rational.h"

#include <sstream>

#include "gtest/gtest.h"

TEST(rational, simple) {
  Rational<int> rat(1, 2);
  EXPECT_EQ(rat.p(), 1);
  EXPECT_EQ(rat.q(), 2);
}

TEST(rational, normalization) {
  Rational<int> rat(2 * 3 * 5, -3 * 5 * 7);
  EXPECT_EQ(rat.p(), -2);
  EXPECT_EQ(rat.q(), 7);
}

TEST(rational, normalization_negative) {
  Rational<int> rat(-3, -7);
  EXPECT_EQ(rat.p(), 3);
  EXPECT_EQ(rat.q(), 7);
}

TEST(rational, zero) {
  Rational<int> rat(0, -42);
  EXPECT_EQ(rat.p(), 0);
  EXPECT_EQ(rat.q(), 1);
}

TEST(rational, stream) {
  std::ostringstream oss;
  Rational<int> rat(-3, 7);
  oss << rat;
  EXPECT_EQ(oss.str(), "-3/7");
}
