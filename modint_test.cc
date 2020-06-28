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

  EXPECT_EQ(ModInt<7>(-2), 5);
  EXPECT_EQ(ModInt<7>(-10), 4);
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

TEST(modint, minus) {
  ModInt<7> m = 2;
  ModInt<7> n = -m;
  EXPECT_EQ(n, -2);
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

TEST(modint, auto_conversion) {
  ModInt<1000000007> a = 123;
  int b = 456;
  EXPECT_EQ(a + b, 579);

  // TODO: Make this work. This sometimes causes a surprising compile error.
  // EXPECT_EQ(b + a, 579);
}

TEST(modint, div) {
  ModInt<7> m = 2;
  EXPECT_EQ(m / 3, 3);

  EXPECT_EQ(ModInt<1000000007>(12345678900000) / 100000, 123456789);
}

TEST(modint, fact) { EXPECT_EQ(ModInt<1000000007>::Fact(100000), 457992974); }

TEST(modint, comb) {
  EXPECT_EQ(ModInt<1000000007>::Comb(100000, 50000), 149033233);
  EXPECT_EQ(ModInt<1000000007>::CombSlow(1000000000, 141421), 516595147);
}

TEST(modint, perm) {
  EXPECT_EQ(ModInt<1000000007>::Perm(100000, 50000), 466765821);
  EXPECT_EQ(ModInt<1000000007>::PermSlow(1000000000, 141421), 780321549);
}

TEST(modint, comparison) {
  ModInt<7> a = 1, b = 2, c = 1;
  EXPECT_FALSE(a == b);
  EXPECT_TRUE(a == c);
  EXPECT_TRUE(a < b);
  EXPECT_FALSE(b < a);
  EXPECT_TRUE(a <= b);
  EXPECT_FALSE(b <= a);
  EXPECT_TRUE(a <= a);
}

TEST(modint, stream) {
  std::ostringstream oss;
  ModInt<7> m = 2;
  oss << m;
  EXPECT_EQ(oss.str(), "2");
}

TEST(modint, pow_inverse) {
  ModInt<7> m = 2;
  EXPECT_EQ(m.Pow(-1), 4);

  EXPECT_EQ(ModInt<1000000007>(2).Pow(-42) * ModInt<1000000007>(2).Pow(42), 1);
}
