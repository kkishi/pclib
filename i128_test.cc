#include "i128.h"

#include <sstream>

#include "gtest/gtest.h"

TEST(i128, simple) {
  i128 a = 1, b = 2;
  i128 c = a + b;
  EXPECT_EQ(c, 3);
}

i128 i128_max = (i128(0x7fffffffffffffff) << 64) | 0xffffffffffffffff;

TEST(i128, stoi128) {
  EXPECT_EQ(stoi128("0"), 0);
  EXPECT_EQ(stoi128("42"), 42);
  EXPECT_EQ(stoi128("-42"), -42);
  EXPECT_EQ(stoi128("170141183460469231731687303715884105727"), i128_max);
}

TEST(i128, istream) {
  i128 a;
  std::stringstream ss("170141183460469231731687303715884105727");
  ss >> a;
  EXPECT_EQ(a, i128_max);
}

TEST(i128, to_string) {
  EXPECT_EQ(to_string(0), "0");
  EXPECT_EQ(to_string(42), "42");
  EXPECT_EQ(to_string(-42), "-42");
  EXPECT_EQ(to_string(i128_max), "170141183460469231731687303715884105727");
}

TEST(i128, ostream) {
  i128 a = i128_max;
  std::stringstream ss;
  ss << a;
  EXPECT_EQ(ss.str(), "170141183460469231731687303715884105727");
}
