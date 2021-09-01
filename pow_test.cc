#include "pow.h"

#include "gtest/gtest.h"
#include "modint.h"

TEST(pow, simple) {
  EXPECT_EQ(Pow(2, 0), 1);
  EXPECT_EQ(Pow(2, 10), 1024);
  int64_t e = 1234567890123456789LL;
  EXPECT_EQ(Pow(2, e, 1000000007), ModInt<>(2).Pow(e).value());
}

constexpr int64_t thousand = Pow(10, 3);
constexpr int64_t sixteen = Pow(2, 4);

TEST(pow, constant) {
  EXPECT_EQ(thousand, 1000);
  EXPECT_EQ(sixteen, 16);
  int64_t x = 5, y = 7;
  EXPECT_EQ(Pow(x, y), 78125);
}
