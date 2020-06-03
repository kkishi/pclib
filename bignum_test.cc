#include "bignum.h"

#include "gtest/gtest.h"

TEST(bignum, bigint) {
  bigint a = 1LL << 60;
  bigint b = a * a;
  EXPECT_EQ(b.str(), "1329227995784915872903807060280344576");
}

TEST(bignum, decfloat) {
  decfloat a("2.51");
  EXPECT_EQ(int(a * 100), 251);

  double b = 2.51;
  EXPECT_EQ(int(b * 100), 250);
}
