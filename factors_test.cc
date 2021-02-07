#include "factors.h"
#include "gtest/gtest.h"

TEST(factorize, factors) {
  EXPECT_EQ(Factors(1), (std::map<int, int>{}));
  EXPECT_EQ(Factors(2), (std::map<int, int>{{2, 1}}));
  EXPECT_EQ(Factors(18), (std::map<int, int>{{2, 1}, {3, 2}}));
  EXPECT_EQ(Factors<int64_t>(2432902008176640000L),
            (std::map<int64_t, int>{{2, 18},
                                    {3, 8},
                                    {5, 4},
                                    {7, 2},
                                    {11, 1},
                                    {13, 1},
                                    {17, 1},
                                    {19, 1}}));
}
