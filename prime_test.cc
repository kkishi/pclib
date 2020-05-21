#include "prime.h"

#include "gtest/gtest.h"

TEST(prime, simple) {
  EXPECT_EQ(Sieve(5),
            std::vector<bool>({false, false, true, true, false, true}));
  EXPECT_EQ(Primes(5), std::vector<int>({2, 3, 5}));

  std::vector<int> p = Primes(1000000);
  EXPECT_EQ(p.back(), 999983);
  EXPECT_EQ(p.size(), 78498);
}
