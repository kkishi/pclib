#include "modint.h"

#include <sstream>

#include "gtest/gtest.h"

TEST(modint, default_construct) {
  ModInt<7> m;
  EXPECT_EQ(m.value(), 0);
}

TEST(modint, construct) {
  ModInt<7> m(10);
  EXPECT_EQ(m.value(), 3);
}

TEST(modint, add) {
  ModInt<7> m(2);
  m += 6;
  EXPECT_EQ(m.value(), 1);

  ModInt<11> a(7);
  ModInt<11> b(8);
  EXPECT_EQ((a + b).value(), 4);
}

TEST(modint, increment) {
  ModInt<7> m(6);
  ++m;
  EXPECT_EQ(m.value(), 0);
}

TEST(modint, sub) {
  ModInt<7> m(2);
  m -= 6;
  EXPECT_EQ(m.value(), 3);

  ModInt<11> a(7);
  ModInt<11> b(8);
  EXPECT_EQ((a - b).value(), 10);
}

TEST(modint, decrement) {
  ModInt<7> m(0);
  --m;
  EXPECT_EQ(m.value(), 6);
}

TEST(modint, mul) {
  ModInt<7> m(2);
  m *= 6;
  EXPECT_EQ(m.value(), 5);

  ModInt<11> a(7);
  ModInt<11> b(8);
  EXPECT_EQ((a * b).value(), 1);
}

TEST(modint, large) {
  ModInt<1000000007> a(2147483647), b(2147483646);
  EXPECT_EQ((a + b).value(), 294967265);
  EXPECT_EQ((a * b).value(), 703135109);
}

TEST(modint, stream) {
  std::ostringstream oss;
  ModInt<7> m(2);
  oss << m;
  EXPECT_EQ(oss.str(), "2");
}
