#include "factorize.h"

#include "gtest/gtest.h"

TEST(factorize, simple) {
  EXPECT_EQ(Factorize(1), (std::map<int, int>{}));
  EXPECT_EQ(Factorize(2), (std::map<int, int>{{2, 1}}));
  EXPECT_EQ(Factorize(18), (std::map<int, int>{{2, 1}, {3, 2}}));
  EXPECT_EQ(Factorize<long long>(2432902008176640000L),
            (std::map<long long, int>{{2, 18},
                                      {3, 8},
                                      {5, 4},
                                      {7, 2},
                                      {11, 1},
                                      {13, 1},
                                      {17, 1},
                                      {19, 1}}));
}
