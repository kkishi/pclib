#include "bignum.h"

#include "gtest/gtest.h"

TEST(bigint, simple) {
  bigint a = 1LL << 60;
  bigint b = a * a;
  EXPECT_EQ(b.str(), "1329227995784915872903807060280344576");
}
