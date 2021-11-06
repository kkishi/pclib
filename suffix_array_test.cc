#include "suffix_array.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::ElementsAre;

TEST(suffix_array, simple) {
  EXPECT_THAT(SuffixArray("abracadabra"),
              ElementsAre(10, 7, 0, 3, 5, 8, 1, 4, 6, 9, 2));
}
