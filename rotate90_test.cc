#include "rotate90.h"

#include "gtest/gtest.h"

TEST(rotate_90, simple) {
  std::vector<std::string> s = {"abc", "def"}, t = {"cf", "be", "ad"};
  EXPECT_EQ(Rotate90(s), t);
}
