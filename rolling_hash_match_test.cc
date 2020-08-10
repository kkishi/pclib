#include "rolling_hash_match.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::ElementsAre;

TEST(rollinghashmatch, simple) {
  EXPECT_THAT(RollingHashMatches("aababcabcdabcde", "ab"),
              ElementsAre(1, 3, 6, 10));
  EXPECT_THAT(RollingHashMatches("aababcabcdabcde", "abcde"), ElementsAre(10));
}
