#include "gtest/gtest.h"
#include "setmax.h"
#include "setmin.h"

TEST(setmin, simple) {
  int a = 3, b = 4;
  EXPECT_FALSE(Setmin(a, b));
  EXPECT_EQ(a, 3);
  EXPECT_EQ(b, 4);
  EXPECT_TRUE(Setmin(b, a));
  EXPECT_EQ(a, 3);
  EXPECT_EQ(b, 3);
}

TEST(setmax, simple) {
  int a = 3, b = 4;
  EXPECT_FALSE(Setmax(b, a));
  EXPECT_EQ(a, 3);
  EXPECT_EQ(b, 4);
  EXPECT_TRUE(Setmax(a, b));
  EXPECT_EQ(a, 4);
  EXPECT_EQ(b, 4);
}
