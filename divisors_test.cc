#include "divisors.h"

#include "gtest/gtest.h"

TEST(divisors, divisors) {
  EXPECT_EQ(Divisors(6), (std::vector<int>{1, 2, 3, 6}));
}
