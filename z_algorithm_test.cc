#include "z_algorithm.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "modint.h"

using testing::ElementsAre;

TEST(z_algorithm, simple) {
  EXPECT_THAT(ZAlgorithm("aardvark"), ElementsAre(8, 1, 0, 0, 0, 1, 0, 0));
  EXPECT_THAT(ZAlgorithm("alfalfa"), ElementsAre(7, 0, 0, 4, 0, 0, 1));
  EXPECT_THAT(ZAlgorithm("msbtmsxcmsbtmsxcmsbtmsbtmsxcmsbtmsxcmsbtmsbtmsxcmsb"),
              ElementsAre(51, 0, 0, 0, 2, 0, 0, 0, 14, 0, 0, 0, 2, 0, 0, 0, 6,
                          0, 0, 0, 31, 0, 0, 0, 2, 0, 0, 0, 14, 0, 0, 0, 2, 0,
                          0, 0, 6, 0, 0, 0, 11, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0));
}

TEST(z_algorithm, zmatch) {
  EXPECT_THAT(ZMatch("aardvark", "ar"), ElementsAre(1, 5));
}
