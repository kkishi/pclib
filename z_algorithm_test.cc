#include "z_algorithm.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "modint.h"

using testing::ElementsAre;

TEST(z_algorithm, simple) {
  EXPECT_THAT(ZAlgorithm("aardvark"), ElementsAre(8, 1, 0, 0, 0, 1, 0, 0));
  EXPECT_THAT(ZAlgorithm("alfalfa"), ElementsAre(7, 0, 0, 4, 0, 0, 1));
}
