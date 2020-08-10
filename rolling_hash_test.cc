#include "rolling_hash.h"

#include <unordered_set>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::ElementsAre;

TEST(rollinghash, simple) {
  std::unordered_set<RollingHash> s;
  for (auto& str : std::vector<std::string>{"abc", "def", "ghi"}) {
    RollingHash h;
    for (char c : str) h.Add(c);
    s.insert(h);
  }
  EXPECT_EQ(s.size(), 3);
}
