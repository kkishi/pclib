#include "modint.h"

#include <sstream>

#include "gtest/gtest.h"

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

TEST(modint, mul) {
  ModInt<7> m(2);
  m *= 6;
  EXPECT_EQ(m.value(), 5);

  ModInt<11> a(7);
  ModInt<11> b(8);
  EXPECT_EQ((a * b).value(), 1);
}

TEST(modint, stream) {
  std::ostringstream oss;
  ModInt<7> m(2);
  oss << m;
  EXPECT_EQ(oss.str(), "2");
}
