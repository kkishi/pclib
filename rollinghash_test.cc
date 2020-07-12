#include "rollinghash.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::ElementsAre;

TEST(rollinghash, simple) {
  EXPECT_THAT(Matches("aababcabcdabcde", "ab"), ElementsAre(1, 3, 6, 10));
  EXPECT_THAT(Matches("aababcabcdabcde", "abcde"), ElementsAre(10));
}
