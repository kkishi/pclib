#include "modint.h"

#include <sstream>

#include "gtest/gtest.h"

TEST(modint, default_construct) {
  ModInt<7> m;
  EXPECT_EQ(m, 0);
}

TEST(modint, construct) {
  ModInt<7> m = 10;
  EXPECT_EQ(m, 3);
}

TEST(modint, add) {
  ModInt<7> m = 2;
  m += 6;
  EXPECT_EQ(m, 1);

  ModInt<11> a = 7, b = 8;
  EXPECT_EQ(a + b, 4);
}

TEST(modint, increment) {
  ModInt<7> m = 6;
  ++m;
  EXPECT_EQ(m, 0);
}

TEST(modint, sub) {
  ModInt<7> m = 2;
  m -= 6;
  EXPECT_EQ(m, 3);

  ModInt<11> a = 7, b = 8;
  EXPECT_EQ(a - b, 10);
}

TEST(modint, decrement) {
  ModInt<7> m;
  --m;
  EXPECT_EQ(m, 6);
}

TEST(modint, mul) {
  ModInt<7> m = 2;
  m *= 6;
  EXPECT_EQ(m, 5);

  ModInt<11> a = 7, b = 8;
  EXPECT_EQ(a * b, 1);
}

TEST(modint, large) {
  ModInt<1000000007> a = 2147483647, b = 2147483646;
  EXPECT_EQ(a + b, 294967265);
  EXPECT_EQ(a * b, 703135109);
}

TEST(modint, stream) {
  std::ostringstream oss;
  ModInt<7> m = 2;
  oss << m;
  EXPECT_EQ(oss.str(), "2");
}
