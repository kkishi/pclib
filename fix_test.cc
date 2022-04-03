#include "fix.h"

#include "gtest/gtest.h"

TEST(fix, fibonacci) {
  int fib10 = Fix([&](auto fib, int n) -> int {
    return n <= 2 ? 1 : fib(n - 1) + fib(n - 2);
  })(10);
  EXPECT_EQ(55, fib10);
}
